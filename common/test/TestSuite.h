#ifndef __OITEST_TEST_H__
#define __OITEST_TEST_H__

#include <string>
#include <list>

#include <vadefs.h>
#include <stdarg.h>

class MessageOutput
{
	virtual void Prompt(const std::string& msg) const = 0;
	virtual void PromptTitle(const std::string& titleMsg) const = 0;
	virtual void PromptMessage(const std::string& msg) const = 0;
	virtual void NewLine() const = 0;
};

class ITest : MessageOutput
{
public:
	ITest();
	ITest(const std::string& name);

protected:
	std::string _name;
	std::string _indent;
	std::string _tab;

public:
	virtual bool Run() = 0;
	virtual void SetIndent(const std::string& indent);
	virtual void SetTab(const std::string& tab);
	void Prompt(const std::string& msg) const;
	void PromptTitle(const std::string& titleMsg) const;
	void PromptMessage(const std::string& msg) const;
	void NewLine() const;
};

class Test : public ITest
{
public:
	Test();
	Test(const std::string& name);

public:
	virtual bool Run();
	virtual bool RunTest() = 0;

	bool Assert(bool assertion, const std::string& errorMsg);

	template <class Type>
	bool AssertEquals(Type a, Type b, const std::string& errorMsg)
	{
		return Assert(a == b, errorMsg);
	}

	template <class Type>
	bool AssertNotEquals(Type a, Type b, const std::string& errorMsg)
	{
		return Assert(!(a == b), errorMsg);
	}
};

class TestSuite : public ITest
{
private:
	std::list<ITest*> _tests;

public:
	TestSuite();
	TestSuite(std::string name);
	TestSuite(std::string name, std::list<ITest*> tests);
	TestSuite(std::string name, int reserved, ...);
	TestSuite(std::list<ITest*> tests);
	virtual ~TestSuite();

public:
	void Add(ITest* test);
	virtual bool Run();
	virtual void SetIndent(const std::string& indent);
	virtual void SetTab(const std::string& tab);
};

#endif // __OITEST_TEST_H__
