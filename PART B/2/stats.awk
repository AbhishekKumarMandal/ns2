BEGIN {
 telnet=0;
 ftp=0;
 telnettotal=0;
 ftptotal=0;
 telnetsize=0;
 ftpsize=0;
}

{
 event=$1;
 type=$5;
 from=$9;
 to=$10;
 psize=$6;
 
 if(type=="tcp")
 {
   if(event=="r" && from==0.0 && to==3.0)
   {
    telnet++;
    telnetsize=psize;
   }
   if(event=="r" && from==1.0 && to==3.1)
   { 
    ftp++;
    ftpsize=psize;
   }
}
 
 telnettotal=telnet*telnetsize*8;
 ftptotal=ftp*ftpsize*8;
}

END {
 printf("\ntelnet throughput: %d\n",telnettotal/24);
 printf("ftp throughput: %d",ftptotal/24);
}
