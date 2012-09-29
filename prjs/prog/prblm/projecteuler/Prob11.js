importPackage(java.io);
importPackage(java.lang);
importPackage(java.util);
function fmpHV(d){
	var max=0;
        var maxv = 0;
  for(var i=0;i<20;i++){
	  var r = d[i];
	  for(var j=0;j<20-4;j++){
             var tmp = r[j]*r[j+1]*r[ j+2]*r[j+3];
	     var tmpv = d[j][i]*d[j+1][i]*d[j+2][i]*d[j+3][i];
	     if(tmpv>maxv){
		     maxv = tmpv;
	     }
	     if(tmp>max){
		     max = tmp;
	     }
	  }
  }
  return Math.max(max,maxv);
}
function fmpD(d){
	var maxd = 0
	for(var i=3;i<20;i++){
		for(var j=0;j<=(i-3);j++){
                   var v  = d[i-j][j]*d[i-j-1][j+1]*d[i-j-2][j+2]*d[i-j-3][j+3];
		   
		   var v1 = d[19-i+j][j]*d[19-i+j+1][j+1]*d[19-i+j+2][j+2]*d[19-i+j+3][j+3];
	           var v2 = d[i-j][19-j]*d[i-j-1][19-j-1]*d[i-j-2][19-j-2]*d[i-j-3][19-j-3];
		   var v3 = d[19-i+j][19-j]*d[19-i+j+1][19-j-1]*d[19-i+j+2][19-j-2]*d[19-i+j+3][19-j-3];

		   var mm = Math.max;
		   maxd = mm(mm(mm(mm(v,v1),v2),v3),maxd);
		   
		}
	}
	return maxd;
}
function findMaxProd(data){
   var a = fmpHV(data);
   var b = fmpD(data);
   return Math.max(a,b);
}
var br = new BufferedReader(new InputStreamReader(System["in"]));
var data  = new Array(20);
for(var i=0;i<20;i++){
	data[i] = new Array(20);
         var st = new StringTokenizer(br.readLine());
	for(var j=0;j<20;j++){
		data[i][j] = st.nextToken();
	}
}
br.close();
System.out.println(new Integer(findMaxProd(data)));
