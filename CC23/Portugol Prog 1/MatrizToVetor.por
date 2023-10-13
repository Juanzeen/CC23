programa
{
	inclua biblioteca Util
	//Criando vetor com os maiores valores de uma matriz 5x5
	inteiro maior = 0
	funcao inteiro ordena(inteiro a, inteiro b){
		se(maior<b){
			maior = b
		}
		retorne maior}

	funcao inicio(){

		inteiro matrizBase[5][5]
		inteiro vetorMaiores[5]

		para(inteiro i = 0 ; i<5;i++){
			para(inteiro j = 0 ; j<5;j++){
				matrizBase[i][j] = Util.sorteia(0,1000)
			}
		}

		maior = matrizBase[0][0]

		para(inteiro i = 0 ; i<5;i++){
			para(inteiro j = 0 ; j<4;j++){
				vetorMaiores[i] = ordena(matrizBase[i][j], matrizBase[i][j+1])
			}
			maior = 0
		}
		
		}
	
		
		
	
		

}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 401; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {maior, 5, 9, 5}-{matrizBase, 14, 10, 10}-{vetorMaiores, 15, 10, 12};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */