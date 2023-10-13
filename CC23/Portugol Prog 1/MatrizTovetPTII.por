programa
{
	inteiro maior = 0
	funcao inteiro acheMaior(inteiro a , inteiro b){
		se(maior<b){
			retorne b}
		
		senao{ 
			retorne maior
			}
	}
	funcao inicio()
	{
		const inteiro tamanhoV = 5 
		const inteiro matriz [tamanhoV][tamanhoV] = {{3,7,90, 4, 2}, {10,3,54,12,4}, {10,3,2,54,290}, {12,32,54,67,98},{1,21,3,54,76}}
			inteiro vetor[5]	
		para(inteiro i = 0; i<tamanhoV; i++){
			para(inteiro j = 0; j<tamanhoV-1;j++ ){
				
				se(maior==0){
				 maior = matriz[i][j]}
				maior = acheMaior(matriz[i][j], matriz[i][j+1])	
				}
				vetor[i] = maior
				maior = 0
			}
		para(inteiro i = 0; i<5;i++){
			escreva(vetor[i], "\t")}
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 146; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {maior, 3, 9, 5}-{a, 4, 34, 1}-{b, 4, 46, 1}-{matriz, 15, 16, 6}-{vetor, 16, 11, 5};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */