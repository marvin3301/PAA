logcut(int cuts[], int logsize){
	for(int i = 0; i < cuts.length; i++){
		return min(cuts[i],s )
	}
}


int cal(int start, int end, int[]cuts){
    if(dp[start][end]!= -1) return dp[start][end];
    int result = 1000000;
    for(int i = 0; i < cuts.length; i++){
       if(cuts[i]> start && cuts[i]<end){
         int val = (end - start + 1) + cal(start, cuts[i], cuts) + cal(cuts[i],end , cuts); 
         result = min(val, result);
       } 
    }
    return dp[start][end] = result;
}







var
  Cuts[] = {0, 2, 4, 7, 10};
  Cost: array of array of Integer;
  CutSequence: array of array of String;
  N, row, col, leftpos, rightpos, cutpos, Sum: Integer;
begin
  Cuts := TArray<Integer>.Create(0, 2, 4, 7, 10); // start, cuts, end points
  N := Length(Cuts);
  SetLength(Cost, N, N);  //zero-initialized 2D array
  SetLength(CutSequence, N, N);  //zero-initialized 2D array

  for rightpos := 2 to N - 1 do
    for leftpos := rightpos - 2 downto 0 do begin //walk along the diagonals
                                                  //using previously computed results
      //find the best (mincost) cut
      Cost[leftpos, rightpos] := MaxInt; //big value
      for cutpos := leftpos + 1 to rightpos - 1 do begin
        Sum := Cost[leftpos, cutpos] + Cost[cutpos, rightpos];
        if Sum < Cost[leftpos, rightpos] then begin
          Cost[leftpos, rightpos] := Sum;
          //write down best sequence
          CutSequence[leftpos, rightpos] := Format('%d %s %s', [Cuts[CutPos],
            CutSequence[leftpos, cutpos], CutSequence[cutpos, rightpos]]);
        end;
      end;

      //add own length
      Cost[leftpos, rightpos] :=
        Cost[leftpos, rightpos] + Cuts[rightpos] - Cuts[leftpos];
    end;

  //show the best result
  Caption := Format('Cost %d  Sequence %s',[Cost[0, N-1], CutSequence[0, N-1]]);



for(int i = 0; i < n; i++)
	c[i][i] = 0;
for(int l = 1; l < n; l++){
	for(i = 0; i < n-l; i++){
		j= i+l;
		for(k = i; k < j-1; k++){
		if(corte(i, j)){
			c[i][j] = j - i + min(c[i][p[k]], c[p[k]][j]);
          	}
          	else
          	c[i][j] = 0;	
		}
	}
}

//QUESTÂO 17
int dia;
int tarefas[n];
ordenaPorMulta(tarefas);
int dias[n];
double multa;
for(int i = n-1; i >= 0; i--){
	if(dias[n] == -1) dias[n] = tarefas[n]
}
if(tarefa[n-1])








