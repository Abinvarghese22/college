class string
{
public static void main(String args[])
{
String str=args[0];
String toCheckStr="hello";
if(str.startsWith(toCheckStr))
{
System.out.println("The string does starts with"+toCheckStr);
}
else{
System.out.println("The string does not starts with"+toCheckStr);
}
}
}
