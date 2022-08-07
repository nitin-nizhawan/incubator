namespace CLRS.Tests;
using CLRS.Part7.Chap32;

public class StringMatchingTest
{
    [Fact]
    public void TestRabinKarp()
    {
         Assert.True(StringMatching.RabinKarp("nitin","nitin") == 0," should be true");
    }

    [Fact]
    public void TestKnuthMorisPratt(){
         Assert.True(StringMatching.KnuthMorrisPratt("nitin","nitin") == 0,"shoudl be true");
    }
}
