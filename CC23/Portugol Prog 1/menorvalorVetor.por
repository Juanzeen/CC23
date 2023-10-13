programa
{
inclua biblioteca Util --> u

	const inteiro tamanho = 200
	inteiro vetor[tamanho], menor, pos

	funcao preencheVetor(){
		para(inteiro i =0; i<tamanho; i++){
			vetor[i] = u.sorteia(0, 10000)
			}
	}	

	
	funcao inicio()
	{
	
	preencheVetor()
	menor = vetor[0]
	para(inteiro i= 0 ; i<tamanho; i++){
		se(menor>vetor[i]){
			menor = vetor[i]
			pos = i}

		se(i==tamanho-1){
		escreva("O menor valor foi: ",menor, " ele está na ", pos, "* do vetor que foi percorrido ", i+1, " vezes")
		}
		}	
	
				
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 201; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */