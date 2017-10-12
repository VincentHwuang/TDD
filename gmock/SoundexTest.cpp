#include"gmock/gmock.h"

class CSoundex
{

};

TEST(SoundexEncoding,RetainSoleLetterOfOneLetterWorld)
{
	CSoundex soundex;
}

int main(int argc,char** argv)
{
	testing::InitGoogleMock(&argc,argv);

	return RUN_ALL_TESTS();
}
