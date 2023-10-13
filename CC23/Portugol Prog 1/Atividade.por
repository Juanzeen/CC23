programa
{
	
	funcao inicio()
	{
		//Programa para cadastro de 8 pessoas
		//quantas mulheres cadastradas, homens com mais de 100kg,media de peso entre mulheres, homem mais pesado

		
		caracter sexo
		real peso, totalPesoM = 0.0, maiorPeso = 0.0
		inteiro totalM = 0, totalH =0, homens100 = 0
		
		
		escreva("Olá usuário, sou um programa que funciona com um loop que roda 8 vezes e guardo as informações de cadastro que você me dá!\n")

		para(inteiro i = 0;i<5;i++){
			escreva("Cadastro da ",i+1,"º pessoa!\n")
		
			escreva("Digite aqui o sexo (M/F): ")
			leia(sexo)
			escreva("Digite aqui o peso: ")
			leia(peso)
			limpa()

			se(sexo=='f' ou sexo=='F'){
				totalM = totalM+1
				totalPesoM = totalPesoM + peso}

			senao se(sexo=='M' ou sexo=='m'){
				totalH = totalH+1
				
				se(peso>100){
				homens100 = homens100+1}
				}

				se(peso>maiorPeso){
					maiorPeso = peso}
			}

				
			

			real mediaPesoM = totalPesoM/totalM 

			escreva("O total de mulheres cadastradas foi: ",totalM)
			escreva("\nO total de homens com mais de 100kg foi: ",homens100)
			escreva("\nA média de peso das mulheres é de: ", mediaPesoM)
			escreva("\nMaior peso entre os homens: ",maiorPeso)
		
	}}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 781; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */