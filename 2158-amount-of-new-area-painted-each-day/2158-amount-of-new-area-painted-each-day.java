class Solution {
    
    public int[] amountPainted(int[][] paint) {
        
       // Arrays.sort(paint,(a,b)->Integer.compare(a[0],b[0]));
        
        List<Integer> res = new LinkedList<Integer>();
         int[] ar = new int[100000];
        
       
        for(int i=0;i<paint.length;i++){
            
            int m = paint[i][0];
            int n = paint[i][1];
            int c =0;
            while(m!=n){
                if(ar[m]!=1){
                    ar[m]=1;
                    c++;
                }
                m++;
            }
            res.add(c);
        }
        
        return res.stream().mapToInt(i->i).toArray();
        
    }
}