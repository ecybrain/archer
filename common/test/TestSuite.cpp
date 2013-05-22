#include <iostream>

#include "testsuite.h"

ITest::ITest() : _name("anonymous"), _indent(), _tab("  ")
{}

ITest::ITest(const std::string& name) : _name(name), _indent(), _tab("  ")
{}

void ITest::Prompt(const std::string& msg) const
{ std::cout << msg; }

void ITest::PromptTitle(const std::string& titleMsg) const
{
	std::cout << _indent << titleMsg;
	NewLine();
}

void ITest::PromptMessage(const std::string& msg) const
{
	std::cout << _indent << _tab << msg;
	NewLine();
}

void ITest::NewLine() const
{
	std::cout << std::endl;
}

void ITest::SetIndent(const std::string& indent)
{ _indent = indent; }

void ITest::SetTab(const std::string& tab)
{ _tab = tab; }

Test::Test()
{}

Test::Test(const std::string& name) : ITest(name)
{}

bool Test::Run()
{
	PromptTitle("Executing " + _name + "...");

	if (!RunTest())
	{
		PromptTitle("Executing " + _name + " failed.");
		return false;
	}

	PromptTitle("Executing " + _name + " successfully.");

	NewLine();
	return true;
}

bool Test::Assert(bool assertion, const std::string& errorMsg)
{
	if (assertion)
		return true;

	PromptMessage(errorMsg);

	return false;
}

TestSuite::TestSuite()
{}

TestSuite::TestSuite(std::string name) : ITest(name)
{}

TestSuite::TestSuite(std::string name, std::list<ITest*> tests) : ITest(name)
{ _tests = tests; }

TestSuite::TestSuite(std::string name, int reserved, ...) : ITest(name)
{
	va_list argList;
	va_start(argList, reserved);
	while (1) 
	{
		ITest* para = va_arg(argList, ITest*);
		if (0 == para)
			break;
		Add(para);
	}
	va_end(argList);
}

TestSuite::TestSuite(std::list<ITest*> tests)
{ _tests = tests; }

TestSuite::~TestSuite()
{
	for (std::list<ITest*>::iterator it = _tests.begin(); it != _tests.end(); it++)
	{
		delete (*it);
	}
}

void TestSuite::Add(ITest* test)
{
	test->SetTab(_tab);
	test->SetIndent(_indent + _tab);
	_tests.push_back(test);
}

bool TestSuite::Run()
{
	bool result = true;

	PromptTitle("Running test suite [" + _name + "]...");
	NewLine();
	
	for (std::list<ITest*>::iterator it = _tests.begin(); it != _tests.end(); it++)
	{
		if (!(*it)->Run())
			result = false;
	}

	PromptTitle("Running test suite [" + _name + "] " + (result ? "successfully." : "failed."));
	NewLine();

	return result;
}

void TestSuite::SetIndent(const std::string& indent)
{
	ITest::SetIndent(indent);
	for (std::list<ITest*>::iterator it = _tests.begin(); it != _tests.end(); it++)
	{
		(*it)->SetIndent(indent+_tab);
	}
}

void TestSuite::SetTab(const std::string& tab)
{
	ITest::SetTab(tab);
	for (std::list<ITest*>::iterator it = _tests.begin(); it != _tests.end(); it++)
	{
		(*it)->SetTab(tab);
	}
	
	SetIndent(_indent);
}
