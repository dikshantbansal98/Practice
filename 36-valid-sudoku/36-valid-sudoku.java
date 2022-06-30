class Solution {
    public boolean isValidSudoku(char[][] a) {
       boolean[] u = new boolean[10];


        for(int i=0; i<9; i++) {
          for(int z=0; z<=9; z++) u[z] = false;
          for(int j = 0; j<9; j++) {
            if (a[i][j] != '.') {
              int value = a[i][j] - '0';
              //System.out.println(value);
              if(u[value]) { System.out.println("Row"); return false; }
              u[value] = true;
            }
          }
                    //for(int z=0; z<9; z++) System.out.print(u[z] + " ");
          //System.out.println();
        }

        for(int i=0; i<9; i++) {
          for(int z=0; z<=9; z++) u[z] = false;
          for(int j = 0; j<9; j++) {
            if (a[j][i] != '.') {
              int value = a[j][i] - '0';
                            //System.out.println(value + " " + a[j][i]);
              if(u[value]) { System.out.println("Column"); return false; }
              u[value] = true;
            }
          }

        }


        for(int i=0; i<9; i+=3) {
          for(int j=0; j<9; j+=3) {
            for(int z=0; z<=9; z++) u[z] = false;

            for(int k=0; k<3; k++) {
              for(int l =0; l<3; l++) {
                int x = i+k;
                int y = j+l;
                if (a[x][y] != '.') {
                  int value = a[x][y] - '0';
                  if(u[value]) return false;
                  u[value] = true;
                }
              }
            }
          }
        }

        return true;
    } 

}