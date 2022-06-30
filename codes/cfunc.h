void uniform(char *str, int len);
double mean(char *str);
double variance(char *str);
void gaussian(char *str, int len);
void uniformtoother(char *str, int len);




//for uniform random variable 
void uniform(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");

for (i = 0; i < len; i++)
{
fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
}
fclose(fp);

}

//for mean
double mean(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;

fp = fopen(str,"r");

while(fscanf(fp,"%lf",&x)!=EOF)
{
i=i+1;

temp = temp+x;
}
fclose(fp);
temp = temp/(i-1);
return temp;}

//for variance
double variance(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0,hump=0.0;

fp = fopen(str,"r");

while(fscanf(fp,"%lf",&x)!=EOF)
{

i=i+1;
temp = temp+x;
hump = hump+x*x;
}
fclose(fp);
temp = temp/(i-1);
hump = hump/(i-1);
double var = hump-temp*temp;
return var;}

//for gaussian random variables
void gaussian(char *str, int len)
{
int i,j;
double temp;
FILE *fp;

fp = fopen(str,"w");

for (i = 0; i < len; i++)
{
temp = 0;
for (j = 0; j < 12; j++)
{
temp += (double)rand()/RAND_MAX;
}
temp-=6;
fprintf(fp,"%lf\n",temp);
}
fclose(fp);

}

//for uniform to other random variables
void uniformtoother(char *str, int len)
{
int i;
double ranvar;
FILE *fp;

fp = fopen(str,"w");
for (i = 0; i < len; i++)
{
ranvar = -2*log(1-(double)rand()/RAND_MAX);
fprintf(fp,"%lf\n",ranvar);
}
fclose(fp);

}
