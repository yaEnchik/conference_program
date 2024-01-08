#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(unittests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::Fail();
		}
	};
}
