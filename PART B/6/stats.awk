BEGIN {
totalftp=0
totalcbr=0;
ftppkt=0;
cbrpkt=0;
ftprec=0;
cbrrec=0;
}

{
 event=$1;
 type=$5;
 size=$6;
 if(event=="r")
 {
  if(type=="tcp")
   {
    ftprec++;
    ftppkt=size;
   }
   if(type=="cbr")
   {
    cbrrec++;
    cbrpkt=size;
   }
 }
 totalftp=ftprec*ftppkt;
 totalcbr=cbrrec*cbrpkt; 
}

END {

 printf("\nFTP throughput: %d\n",totalftp/123);
 printf("\nCBR throughput: %d\n",totalcbr/124);
}
