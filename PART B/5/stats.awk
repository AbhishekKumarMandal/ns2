BEGIN {
 tcpsend=0;
 tcpreceive=0;
 tcplost=0;
 
 udpsend=0;
 udpreceive=0;
 udplost=0;
}

{
 event=$1;
 type=$5;
 if(event=="+")
 {
  if(type=="tcp")
   tcpsend++;
  if(type=="cbr")
   updsend++;
 }
 if(event=="r")
 {
  if(type=="tcp")
   tcpreceive++;
  if(type=="cbr")
   udpreceive++;
 }
 if(event=="d")
 {
  if(type=="tcp")
   tcplost++;
  if(type=="cbr")
   udplost++;
 }

}

END {
 printf("\n tcp send: %d receive: %d lost: %d\n", tcpsend, tcpreceive, tcplost);
 printf("udp send: %d receive: %d lost: %d\n", udpsend, udpreceive, udplost);
}
