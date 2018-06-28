#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


int unbinning(int sampno)
{
using namespace std;
    long double a,b, small, big, bin=1;
    long int count=0, sampno1, rows;
    fstream reader;
    fstream writer;
reader.open("bootsamp.txt");
writer.open("singlesampunbin.txt", ios::out);

while(!reader.eof())
{
    if(!reader)
        break;
reader>>sampno1;
reader>>rows;
if(sampno1=sampno)
	{
	for(long int j=1;j<=rows; j++)
	{
	reader>>a;
	reader>>b;
	for(int i=1;i<=b;i++)
	{
	writer<<a<<"\n";
	}
	}
	break;
	}
else
	{
	for(long int j=1;j<=rows; j++)
	{
	reader>>a;
	reader>>b;
	}
}
}
writer.close();
return 0;
}



int binning(int sampno)
{
using namespace std;
    long double a, small, big, bin=1;
    long int count=0;
    fstream reader;
    fstream writer;
    writer.open("bootsamp.txt",ios::out|ios::app);
    reader.open("bootsampunbin.txt");
if(!reader.eof())
{
reader>>a;
big=a;
small=a;
}

	while(!reader.eof())
{
    reader>>a;
if(reader.eof())
break;

if(a>big)
big=a;

if(a<small)
small=a;

}
cout<<"\n big: "<<big<<" and small:"<<small;
reader.close();
writer<<"\n \n \n"<<sampno<<"\t"<<big-small+1<<"\n";

//double perc=0;
//double perci=5;
//cout<<"\n The width of bin is: "<<bin;
//cout<<"\n Binning data please wait: \n";
for(double i=small;i<=big;i=i+bin)//lower limit is inclusive in bins
{
//perc=((i-small)*100/(big-small));
reader.open("bootsampunbin.txt");


while(!reader.eof())
{
    reader>>a;
if(reader.eof())
break;

		if(a>=i && a<(i+bin))
			{
			count++;
			}
//if(((perc/perci)-1)>=0)
//	{
	//cout<<perci<<"percent complete \n";
//	perci=perci+5;
//	}


}
reader.close();
if(count!=0)
writer<<i<<"\t"<<count<<"\n";
count=0;
}
writer.close();
    return 0;

}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

double stderror(fstream &file, long int count, long int bootnos, long double mean1, long double var1, long double skew1, long double kurt1)
{//function to write standard error
long double meanm=0, varm=0, a, stddev,meanv=0, varv=0,meansk=0, varsk=0,meanku=0, varku=0;
long int x=0;
	while(!file.eof())
{   file>>x;
if(x>bootnos)
break;

if(file.eof())
break;
file>>a;
meanm=meanm+a;
file>>a;
meanv=meanv+a;
file>>a;
meansk=meansk+a;
file>>a;
meanku=meanku+a;

}
meanm=meanm/count;
meanv=meanv/count;
meansk=meansk/count;
meanku=meanku/count;
file.clear();
file.seekg(0, ios::beg);
while(!file.eof())
{
    file>>a;
if(file.eof())
break;
varm=varm+(a-meanm)*(a-meanm);
varv=varv+(a-meanv)*(a-meanv);
varsk=varsk+(a-meansk)*(a-meansk);
varku=varku+(a-meanku)*(a-meanku);
}
varm=varm/(count-1);
varv=varv/(count-1);
varsk=varsk/(count-1);
varku=varku/(count-1);


fstream writeerror;
writeerror.open("bootstderror.txt",ios::app|ios::out);
writeerror<<"\n"<<bootnos<<"\t"<<sqrt(varm)<<"\t"<<sqrt(varv)<<"\t"<<sqrt(varsk)<<"\t"<<sqrt(varku);
writeerror.close();

return 0;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main ()
{
using namespace std;

srand (time(NULL));
 long double a, *b, *c, mean1=0, var1=0,stddev=0, skew1=0, kurt1=0;
    long int count=0, random=0;
int rows=0;
    fstream reader;
    reader.open("7_7GeV0_5unbinned.txt");
cout<<"\n Reading data: ";
	while(!reader.eof())
{
    reader>>a;
//cout<<" "<<a;
if(reader.eof())
break;
mean1=mean1+a;
count++;
    //cout<<a;
    //cout<<"\n";

}
cout<<"\n count:"<<count;
mean1=mean1/count;
reader.close();
//reader.seekg(0,ios::beg);
reader.open("7_7GeV0_5unbinned.txt");
cout<<"\n calculating moments ";
while(!reader.eof())
{
    reader>>a;
if(reader.eof())
break;
var1=var1+(a-mean1)*(a-mean1);
skew1=skew1+(a-mean1)*(a-mean1)*(a-mean1);
kurt1=kurt1+(a-mean1)*(a-mean1)*(a-mean1)*(a-mean1);
}
cout<<"\n addition finished";
var1=var1/(count-1);
cout<<"\n addition finished"<<var1;
stddev=sqrt(var1);
cout<<"\n addition finished"<<stddev;
skew1=skew1/(count*pow(stddev,3));
cout<<"\n addition finished"<<skew1;
kurt1=(kurt1/(count*pow(stddev,4)))-3;
cout<<"\n addition finished"<<kurt1;
cout<<"\n finished calculating moments for original sample";
reader.clear();
reader.close();
cout<<"\n finished calculating moments for original sample";
fstream reader1;
reader1.open("7_7GeV0_5unbinned.txt");//create array with numbers

b=new long double[count];//original sample
c=new long double[count];//bootstrap sample while calculating moments
long int i=0;
cout<<"reader 1";
	while(!reader1.eof())
{
    reader1>>b[i];
if(reader1.eof())
break;
i++;
}
reader1.close();
int sampno=0;//to count already written samples
fstream readsamp;
	readsamp.open("bootsamp.txt");
	cout<<"finished creatin array";
while(!readsamp.eof())
{
    if(!readsamp)
        break;
readsamp>>sampno;
readsamp>>rows;

for(long int j=1;j<=rows; j++)
{
	reader>>a;
	reader>>a;
}
}
cout<<"finished readin samples";
readsamp.close();
int sampno1=sampno;
int bootnos=100;
cout<<"\n Creatin bootstrap samples";
if(sampno<=bootnos)
{
for(;sampno<=bootnos;sampno++)
{
	fstream writesamp;
	writesamp.open("bootsampunbin.txt",ios::out);//file to write particular bootstrap sample to
	if(sampno%20==0)
	cout<<"\n creating sample no. "<<sampno;

	for(long int i=1; i<=count; i++)
	{
  	random = rand() % count;
	writesamp<<"\t"<<b[random];
	}
	writesamp.close();
binning(sampno);//write to bootstrap sample storage
}
}
cout<<"\n reading sample moments already calculated";
fstream writesampmom;
fstream readsampmom;
readsampmom.open("bootsampmom.txt");//to read no. of already calculated moments
while(!readsampmom.eof())
{
    if(!readsampmom)
        break;
readsampmom>>sampno;
for(long int j=1;j<=count; j++)
{
    reader>>a;
}
}
readsamp.close();

cout<<"\n sample moments being calculated";
for(;sampno<=bootnos;sampno++)
{
unbinning(sampno);
	readsamp.open("singlesampunbin.txt");
	while(!readsamp.eof())
	{
			writesampmom.open("bootsampmom.txt",ios::out|ios::app);
			long double mean=0, var=0,stddev=0, skew=0, kurt=0;

			for(long int j=1;j<=count; j++)
			{
			readsamp>>c[j];
			mean=mean+c[j];
			}
			mean=mean/count;

			for(long int k=1;k<=count; k++)
			{
			var=var+(c[k]-mean)*(c[k]-mean);
			skew=skew+(c[k]-mean)*(c[k]-mean)*(c[k]-mean);
			kurt=kurt+(c[k]-mean)*(c[k]-mean)*(c[k]-mean)*(c[k]-mean);
			}
			var=var/(count-1);
			stddev=sqrt(var);
			skew=skew/(count*pow(stddev,3));
			kurt=(kurt/(count*pow(stddev,4)))-3;
			writesampmom<<"\n"<<sampno<<"\t"<<mean<<"\t"<<var<<"\t"<<skew<<"\t"<<kurt;
			writesampmom.close();


	}
	readsamp.close();
}
long int bootnos1;
fstream readstderror;
readstderror.open("bootstderror.txt");//to read no. of already calculated standard errors
while(!readstderror.eof())
{
readstderror>>bootnos1;
for(int m=1;m<=4; m++)
{
    readstderror>>a;
}
}
readstderror.close();
cout<<"\n Calculating errors";
for(;bootnos1<bootnos;bootnos1=bootnos1+100)
{
readsampmom.open("bootsampmom.txt");//to use it to calculate stderror
stderror(readsampmom, count, bootnos1, mean1, var1, skew1, kurt1);
readsampmom.close();
}



    return 0;
}

