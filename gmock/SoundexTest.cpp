#include"gmock/gmock.h"
#include"Soundex.h"

using namespace testing;

//Using 'fixture' class to declare the same class instance using several times in different tests
class CSoundexEncoding: public Test
{
	public:
		CSoundex soundex;
};

  //Tests without using 'fixture' class
//TEST(SoundexEncoding,RetainSoleLetterOfOneLetterWorld)
//{
//	CSoundex soundex;
//	auto encoded=soundex.encode("A");
//
//	ASSERT_THAT(encoded,Eq("A000"));
//}
//
//TEST(SoundexEncoding,PadsWithZerosToEnsureThreeDigits)
//{
//	CSoundex soundex;
//	auto encoded=soundex.encode("l");
//	ASSERT_THAT(encoded,Eq("l000"));
//}

//To use 'fixture' class,we must use 'TEST_F'('F' for 'fixture') instead of 'TEST' macro
TEST_F(CSoundexEncoding,PadsWithZerosToEnsureThreeDigits)
{
//	auto encoded=soundex.encode("l");
//	ASSERT_THAT(encoded,Eq("l000"));
	ASSERT_THAT(soundex.encode("l"),Eq("l000"));
}

TEST_F(CSoundexEncoding,RetainsSoleLetterOfOneLetterWord)
{
	ASSERT_THAT(soundex.encode("Ab"),Eq("A100"));
}

TEST_F(CSoundexEncoding,ReplacesConsonantsWithAppropriateDigits)
{
	ASSERT_THAT(soundex.encode("Ax"),Eq("A200"));
}
int main(int argc,char** argv)
{
	testing::InitGoogleMock(&argc,argv);

	return RUN_ALL_TESTS();
}
