#include <iostream>
#include <string>
#include <random>
#include <map>
#include <functional>

class Solution
{
public:
	std::string encode(std::string& longUrl)
	{
		// check if the long URL has already been encoded
		if (mLong2Short.find(longUrl) != mLong2Short.end())
		{
			return mURLPrefix + mLong2Short[longUrl];
		}

		std::random_device randomGen;
		std::string lShort(6, '0');

		// generate a new short URL
		for (int i = 0; i < 6; i++)
		{
			unsigned int lRandomNum = randomGen();
			lRandomNum %= 62;

			if (lRandomNum < 10)
			{
				lShort[i] = char('0' + lRandomNum);
			}
			else if (lRandomNum < 36)
			{
				lShort[i] = char('A' + lRandomNum - 10);
			}
			else
			{
				lShort[i] = char('a' + lRandomNum - 36);
			}
		}

		mShort2Long[lShort] = longUrl;
		mLong2Short[longUrl] = lShort;

		return mURLPrefix + lShort;
	}

	std::string decode(std::string& shortUrl)
	{
		std::string lShort = shortUrl.substr(mPrefixLen, 6);

		return mShort2Long[lShort];
	}

	Solution() : mURLPrefix("http//tinyurl.com/")
	{
		mPrefixLen = mURLPrefix.size();
	}

private:
	std::string mURLPrefix;
	int mPrefixLen;
	std::map<std::string, std::string> mLong2Short;
	std::map<std::string, std::string> mShort2Long;
};

int main()
{
	std::string lURL = "https://mstr.com/huye/hahu/hurry";
	std::string lURL2 = "https://mstr.com/huye/hahu/ry";

	Solution lTest;

	std::string lShort = lTest.encode(lURL);
	std::string lShort2 = lTest.encode(lURL2);

	std::cout<<lShort<<std::endl;
	std::cout<<lShort2<<std::endl;

	std::cout<<lTest.decode(lShort)<<std::endl;
	std::cout<<lTest.decode(lShort2)<<std::endl;

	return 0;
}
