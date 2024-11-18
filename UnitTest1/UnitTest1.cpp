#include "pch.h"
#include "CppUnitTest.h"
#include "../PDC_LAB14/Source.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestIsAntisymmetric)
		{
			n = 4;
			m = 3;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graph[i][j] = 0;
				}
			}
			graph[0][1] = 1; 
			graph[1][2] = 1; 
			graph[0][2] = 1; 

			bool result = isAntisymmetric();

			Assert::IsTrue(result, L"Відношення має бути антисиметричним.");
		}

		TEST_METHOD(TestIsTransitive)
		{
			n = 4;
			m = 3;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graph[i][j] = 0;
				}
			}
			graph[0][1] = 1; 
			graph[1][2] = 1; 
			graph[0][2] = 1;

			bool result = isTransitive();

			Assert::IsTrue(result, L"Відношення має бути транзитивним.");
		}

	};
}
