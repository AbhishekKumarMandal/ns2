// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// #include<iostream>

// using namespace std;

// char* chksum(char a[], char b[], int length, char carry);

// char* chksum(char a[], char b[], int length, char carry)
// {
//         //printf("entered in function\n");
//         char *sum = new char[16];
//         for(int i=length-1;i>=0;i--)
//         {
//             if(a[i]=='0' && b[i]=='0' && carry=='0')
//             {
//                 sum[i]='0';
//                 carry='0';
//             }
//             else if(a[i]=='0' && b[i]=='0' && carry=='1')
//             {
//                 sum[i]='1';
//                 carry='0';
 
//             }
//             else if(a[i]=='0' && b[i]=='1' && carry=='0')
//             {
//                 sum[i]='1';
//                 carry='0';
 
//             }
//             else if(a[i]=='0' && b[i]=='1' && carry=='1')
//             {
//                 sum[i]='0';
//                 carry='1';
 
//             }
//             else if(a[i]=='1' && b[i]=='0' && carry=='0')
//             {
//                 sum[i]='1';
//                 carry='0';
 
//             }
//             else if(a[i]=='1' && b[i]=='0' && carry=='1')
//             {
//                 sum[i]='0';
//                 carry='1';
//             }
//             else if(a[i]=='1' && b[i]=='1' && carry=='0')
//             {
//                 sum[i]='0';
//                 carry='1';
 
//             }
//             else if(a[i]=='1' && b[i]=='1' && carry=='1')
//             {
//                 sum[i]='1';
//                 carry='1';
 
//             }
//             else
//                 break;
//         }

//         //printf("sum: %s\n",sum);

//         //printf("carry: %c\n",carry);
//         if(carry=='1')
//         {
//             carry='0';
//             for(int i=0;i<length-1;i++)
//                 {
//                     //printf("%c",sum[i]);
//                     b[i]='0';
//                 }
//             b[length-1]='1';
//             //printf("%s\n",b);
            
//             chksum(sum, b,length, carry);
//         }
//         else
//         {
//             return(sum);
//         }

// }

// // char * complement(char arr[],int length)
// // {
// //     char *c= new char[length];
// //     for (int i=0;i<length;i++)
// //     {
// //         if(arr[i]=='1')
// //             c[i]='0';
// //         if(arr[i]=='0')
// //             c[i]='1';
// //     }

// //     return(c);
// // }
// int main()
// {
//     char a[20],b[20];
//     //char sum[20],complement[20];
//     int i,length,flag=0;
    
//     char *p,*q;
    
//     printf("Enter first binary string[16-bits]\n");
//     scanf("%s",a);
//     printf("Enter second binary string[16-bits]\n");
//     scanf("%s",b);
    
//     if(strlen(a)!=16||strlen(b)!=16)
//     {
//         printf("please enter 16 bit data.\n");
//         exit(0);
//     }
    
//     if(strlen(a)==strlen(b))
//     {
//         length = strlen(a);
//         char carry='0';

//         p=chksum(a, b, length, carry);
//         printf("\nSum=%s",p);
//         char sender[16]; //sender will contain checksum.
//         for(int i=0;i<length;i++)
//         {
//             if(p[i]=='0')
//                 sender[i]='1';
//             if(p[i]=='1')
//                 sender[i]='0';
//         }
//         //char *complement=complement(p,length);
//         printf("\nSender Checksum=%s\n",sender);

//         //////////////////////////////////////////////////////////////////////////////////////////////////////////////
//         printf("\n\nchecksum sended to receiver side\n");
//         char receiver[16];
//         q=chksum(p, sender, length, carry);
//         //q=complement(q,length);
//         printf("received:%s\n",q);
//         for(int i=0;i<length;i++)
//         {
//             if(q[i]=='0')
//                 receiver[i]='1';
//             if(q[i]=='1')
//                 receiver[i]='0';
//         }
//         printf("\nfinal output: %s",receiver);
//         printf("\nlength:%d\n",length);
//         for(int i=0;i<length;i++)
//         {
//             if(receiver[i]!=0)
//             {
//                 printf("\nerror detected");
//                 flag=1;
//                 break;
//             }
//         }

//         if(flag==0)
//             printf("\ndata transfered successfully. No error");
//         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//         char choice,err;
//         int pos;
//         printf("\nwant error detection?[y/n]:");
//         cin>>choice;
//         if(choice=='Y'||choice=='y')
//         {
//             printf("\nenter error data in checksum along with position");
//             cin>>err>>pos;
//             if(err!='0'&& err!='1'||pos>16)
//                 cout<<"entered wrong data try again\n";
//             else
//             {
//                 sender[pos]=err;
//                 printf("new sender chksum: %s\n",sender);
//                 q=chksum(p,sender,length,carry);
//                 //q=complement(q,length);
//                 for(int i=0;i<length;i++)
//                 {
//                     if(q[i]=='0')
//                         receiver[i]='1';
//                     if(q[i]=='1')
//                         receiver[i]='0';
//                 }

//                 for(int i=0;i<length;i++)
//                 {
//                     if(receiver[i]!=0)
//                     {
//                         printf("error detected\n");
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
//     else 
//         printf("\nWrong input strings try again.");
// }
 
#include<iostream>
#include<string>
using namespace std;
int chksum(int flag)
{
    string inp;
    int sum=0;
    cout<<"input your string:";
    cin>>inp;
    int n=inp.length();
    if(n%2==0)
        n=n/2;
    else
        n=(n+1)/2;
    for(int i=0;i<n;i++)
    {
        int temp=inp[i*2];
        cout<<"\n"<<inp[(i*2)+1];
        temp=(temp*256)+inp[(i*2)+1];//converts pair of string into decimal value.//
        sum+=temp;
    }
    if(flag==1)
    {
        int chk;
        cout<<"\nenter chksum value:";
        cin>>chk;
        sum+=chk;
    }

    int x,l;
    if(sum>=65536)
    {
        x=sum/65536;
        l=sum%65536;
        sum=l+x;
    }
    sum=65535-sum;
    return sum;
}

int main()
{
    int choice,sum;
    cout<<"1 encode\n2 decode\n3 exit";
    do
    {
        cout<<"\nenter your choice";
        cin>>choice;
        switch(choice)
        {
            case 1: sum=chksum(0);
                    cout<<"chksum is:"<<sum<<"\n";
                        break;
            case 2: sum=chksum(1);
                    if(sum!=0)
                        cout<<"\nerror detected";
                    else
                        cout<<"data transfered successfully";
                        break;
            case 3: cout<<"over.\n";
                        break;
            default:cout<<"\nwrong choice";
        }
    } while(choice!=3);
}