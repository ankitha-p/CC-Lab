<<<<<<< HEAD
import java.io.*;
import java.util.*;
class S{
	String tok;
	String pat;
	S(String s1,String s2){
		tok=s1;
		pat=s2;
	}
}
public class LexSourceScanner{
	public static void main(String args[])throws Exception{
		HashMap<String,S> map=new HashMap<String,S>();
		//initialisation
		map.put("*",new S("mul","multiplication"));
		map.put("/",new S("div","division"));
		map.put("+",new S("add","addition"));
		map.put("-",new S("sub","subtraction"));
		map.put("%",new S("mod","remainder"));
		map.put("<",new S("rel","less than"));
		map.put(">",new S("rel","great than"));
		map.put("=",new S("equal","assignment"));
		map.put("int",new S("dtype","intger data type"));
		map.put("float",new S("dtype","fraction data type"));
		map.put("main",new S("keyword"," main function"));
		map.put("printf",new S("keyword"," output function"));
		map.put("(",new S("pare","open parenthesis"));
		map.put(")",new S("pare","closing parenthesis"));
		map.put("{",new S("brace","open brace"));
		map.put("}",new S("brace","closing brace"));
		map.put(";",new S("semi","end of the statement"));
		map.put("#",new S("hash","inclusion operator"));
		map.put("include",new S("keyword","Inclusion of header files"));
		map.put("stdio.h",new S("hfile","Name of the header file"));
		map.put("\"",new S("Quote","Quotation"));
		FileInputStream fis=new FileInputStream("source1.c");
		Scanner scan=new Scanner(fis);
		String str="";
		while(scan.hasNextLine()){
				str=str+scan.nextLine();		
		}
		System.out.println(str);
		int num=0;
		StringTokenizer st=new StringTokenizer(str," =*/+-%#{}<>;()\"",true);
		while(st.hasMoreTokens()){
			String temp=st.nextToken();
			if(map.containsKey(temp)){
				S t=map.get(temp);
				System.out.println(t.tok+"\t\t\t"+temp+"\t\t\t"+t.pat+"\n");
			}	
			else{	
				
				if(temp.equals(" "))
					System.out.println("Space" + "\t\t\t"+ "Space" +"\t\t\t Space");
				
				else if(temp.charAt(0)<=57 && temp.charAt(0)>=48)
					System.out.println("num"+num+"\t\t\t"+temp+"\t\t\t integer");
				else{
					System.out.println(temp+"******");
					System.out.println("id"+num+"\t\t\t"+temp+"\t\t\t variable");
					num++;
				} 
				
			}
		}		
		
	}
}
=======
import java.io.*;
import java.util.*;
class S{
	String tok;
	String pat;
	S(String s1,String s2){
		tok=s1;
		pat=s2;
	}
}
public class LexSourceScanner{
	public static void main(String args[])throws Exception{
		HashMap<String,S> map=new HashMap<String,S>();
		//initialisation
		map.put("*",new S("mul","multiplication"));
		map.put("/",new S("div","division"));
		map.put("+",new S("add","addition"));
		map.put("-",new S("sub","subtraction"));
		map.put("%",new S("mod","remainder"));
		map.put("<",new S("rel","less than"));
		map.put(">",new S("rel","great than"));
		map.put("=",new S("equal","assignment"));
		map.put("int",new S("dtype","intger data type"));
		map.put("float",new S("dtype","fraction data type"));
		map.put("main",new S("keyword"," main function"));
		map.put("printf",new S("keyword"," output function"));
		map.put("(",new S("pare","open parenthesis"));
		map.put(")",new S("pare","closing parenthesis"));
		map.put("{",new S("brace","open brace"));
		map.put("}",new S("brace","closing brace"));
		map.put(";",new S("semi","end of the statement"));
		map.put("#",new S("hash","inclusion operator"));
		map.put("include",new S("keyword","Inclusion of header files"));
		map.put("stdio.h",new S("hfile","Name of the header file"));
		map.put("\"",new S("Quote","Quotation"));
		FileInputStream fis=new FileInputStream("source1.c");
		Scanner scan=new Scanner(fis);
		String str="";
		while(scan.hasNextLine()){
				str=str+scan.nextLine();		
		}
		System.out.println(str);
		int num=0;
		StringTokenizer st=new StringTokenizer(str," =*/+-%#{}<>;()\"",true);
		while(st.hasMoreTokens()){
			String temp=st.nextToken();
			if(map.containsKey(temp)){
				S t=map.get(temp);
				System.out.println(t.tok+"\t\t\t"+temp+"\t\t\t"+t.pat+"\n");
			}	
			else{	
				
				if(temp.equals(" "))
					System.out.println("Space" + "\t\t\t"+ "Space" +"\t\t\t Space");
				
				else if(temp.charAt(0)<=57 && temp.charAt(0)>=48)
					System.out.println("num"+num+"\t\t\t"+temp+"\t\t\t integer");
				else{
					System.out.println(temp+"******");
					System.out.println("id"+num+"\t\t\t"+temp+"\t\t\t variable");
					num++;
				} 
				
			}
		}		
		
	}
}
>>>>>>> 63f01a10093bbe0919ec4a018c5280b9998052a0
