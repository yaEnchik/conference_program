#include "pch.h"
#include "CppUnitTest.h"

#include "../conference_program/conference_structure.h"
#include "../conference_program/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace unittests
{
	conference_structure* build_conference(std::string startTime, std::string endTime) {
		conference_structure* conference = new conference_structure;
		conference->startTime = startTime;
		conference->endTime = endTime;
		return conference;
	}

	void delete_conferences(conference_structure* array[], int size) {
		for (int i = 0; i < size; i++) {
			delete array[i];
		}
	}
	TEST_CLASS(unittests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			conference_structure* conferences[3];
			conferences[0] = build_conference("11:00", "11:10"); // 10 минут 
			conferences[1] = build_conference("14:00", "14:30"); // 30 минут
			conferences[2] = build_conference("11:00", "11:05"); // 5 минут 
			Assert::AreEqual(conferences[1], get_longest_theme(conferences, 3));
			delete_conferences(conferences, 3);
		}
	};
}
