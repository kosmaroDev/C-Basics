# C Basics

	The convention of C Language:

	- variáveis: snake_case;
	- ponteiros: O * deve estar junto do nome da variável ao ínves de estar junto ao tipo;

	Para mais informações de convenção, consulte: https://www.doc.ic.ac.uk/lab/cplus/
	cstyle.html#N10081

## In memory Variables:

	Em linguagem C, cada variável está associada a:
		- U nome;
		- Um tipo;
		- Um valor;
		- Um endereço:

		Exemplo:

			int a = 10; -> nome: a, tipo: int, valor: 10, &a = 3020 (primeiro bit, mas
			ocupará 3020, 3021, 3022, 3023).

			int b; -> nome b, tipo: int, valor: lixo de memória qualquer pois ainda não
			houveatribuição de valor; &b = 3024.

			int c; -> nome c, tipo: int, valor: lixo de memória qualquer pois ainda não
			houve atribuição de valor; &b = 3028.

			b = 20; -> tipo: int, valor: 20; &b = 3024.

			c = a + b; -> tipo: int, valor: 30; &b = 3028.

	O tipo int precisa de 4 bytes (32 bits) na memória para ser alocado.

	Ordem de alocação dos bits:
		- Little-endian: O valor menos significante é guardado primeiro, ou seja, é guardado
		da esquerda para direita.
		- Big-endian: O valor mais significante é guardado primeiro, ou seja, é guardado da
		direita para esquerda.

	 Em C, podemos acessar o valor guardado dentro da variável usando o nome da variável e
	 também podemos acessar o endereço de memória onde a variável está alocada usando o
	 símbolo '&' precedendo o nome da variável. Por exemplo, acessando valor e endereço de
	 memória da variável 'a':

	 a = 10;
	 &a = 3020;

	 É importante lembrar, por mais que pareça óbvio, que ao ser guardado em memória, o valor
	 é guardado como binário. O endereço de memória é hexadecimal.

## Introduction to Pointers:

	Um ponteiro é um tipo de Dados que guarda endereços de memória (referência) de variáveis.
	O conteúdo do ponteiro é o mesmo conteúdo do endereço de memória da variável a qual ele
	aponta, que é o valor da variável apontada.

	Analogia:

		jogadorDoBarcelona messi = 10; -> nome: messi, tipo: jogadorDoBarcelona, valor: 10,
		&messi = avenida do messi.

		carteiroDoBarcelona jaiminho = &messi; -> nome: jaiminho, tipo: carteiroDoBarcelona,
		valor: &messi = avenida do messi, &jaiminho = rua do jaiminho.

		Ou seja,

			jaiminho = &messi; -> jaiminho = avenida do messi;
			&jaiminho = rua do jaiminho;
			*(jaiminho) = *(avenida do messi) = messi = 10;

	Para declarar ponteiros, a sintaxe é: tipoDeDado *nomePonteiro, ou seja, ponteiros só
	apontam para dados do tipo que ele foi declarado. Todo ponteiro, i.e. endereços de
	memória, ocupam 8 bytes.

### Pointers of pointers:

	Ponteiros de ponteiros são tipos de dados que apontam outros ponteiros. Na analogia
	anterior dos carteiros e jogadores do Barcelona, um ponteiro de ponteiros seria um
	carteiro que envia correspondencia para os 'carteiroDoBarcelona'.

	Analogia:

		carteiroDeCarteiroDoBarcelona sebastiao = &jaiminho; -> nome: sebastiao, tipo:
		carteiroDeCarteiroDoBarcelona, valor: &jaiminho = rua do jaiminho, &sebastiao = rua
		do sebastiao.

		Ou seja,

			sebastiao = &jaiminho; -> sebastiao = rua do jaiminho;
			&sebastiao = rua do sebastiao;
			*(sebastiao) = *(rua do jaiminho) = avenida do messi;
			**(sebastiao) = **(rua do jaiminho) = *(avenida do messi) = messi = 10;

### Pointer's Arithmetic

	Como visto acima, o SO acessa os elementos do array pelo índice retornando o conteúdo
	do endereço de memória que o elemento ocupa e também nome do array pode ser usado para
	pegar o endereço de memória do primeiro elemento. Com base nisso podemos entender como
	SO consegue pegar através do endereço de memória.

	Suponha que exista um array:

		tipo array[n];

	Caso desejássemos pegar o elemento de índice m, com 0 <= m < n. Esse elemento pode ser
	acessado usando array[m]. Mas o que é feito por baixo dos panos?

		Lembrando-se que poderiamos escrever: array[0] = *&array[0] = *&array = *array, é
		possível fazer uma generização do acesso por índices. Ou seja,

			array[0] = *&array[0] = *&(array + 0) = *(array + 0)
			array[1] = *&array[1] = *&(array + 1) = *(array + 1)
			.
			.
			.
			array[m] = *&array[m] = *&(array + m) = *(array + m)
			.
			.
			.
			array[n-1] = *&array[n-1] = *&(array + (n-1)) = *(array + (n-1))

		Então se quisermos acessar o 3º elemento de array fazemos:

			array[2] = *&array[2] = *&(array + 2) = *(array + 2)

		Suponha que o tipo de dados do array seja int e que o endereço de array[0] seja
		5000, ou seja:

			int array[n];

		Nesse caso a sentença abaixo:

			array[2] = *&array[2] = *&(array + 2) = *(array + 2)

		**não siginifica:**

			array[2] = *&array[2] = *&(5000 + 2) = *(5002)

		mas sim:

			array[2] = *&array[2] = *&(array + 2*tamanho_em_bytes_do_tipo) = *(array + 8) =
			*(5008)

		Logo, a sentença abaixo:

			array[m] = *&array[m] = *&(array + m) = *(array + m)

		significa:

			array[m] = *&array[m] = *&(array + m*tamanho_em_bytes_do_tipo) = *(array +
			m*tamanho_em_bytes_do_tipo)

	Essa é a lógica da aritmética de ponteiros, mas foi explicada usando arrays pois o
	símbolo do array pode ser interpretado como um 'ponteiro'. Veja o arquivo:
	aritmetica_de_ponteiros.c

## Functions

	São estruturas que agrupam um bloco de comando, que retornam um único valor ao final da
	execução.

	Como declarar uma função em C:


		tipo_do_retorno nomeFuncao(tipo param1, tipo param2, ...){

			comandos...

			return valor_de_retorno
		}

	É importante destacar que os parametros não precisam ser do mesmo tipo, mas o valor
	retornado deve sempre ser do tipo 'tipo_do_retorno'.

	Para funções que não retornam nada (ou seja o tipo do retorno é void), não precisa usar
	o return.

	Em C as funções não podem ser declaradas dentro de outras funções, porém você pode
	chamar funções dentro de outras funções. Também não é possível fazer sobrecarga de
	funções, mesmo com assinaturas distintas.

	Éxistem duas formas de passar parametros para funções. Por valor e por referencia.

		- Por valor: é feita uma cópia do argumento (variável passada), podendo manipular o
		valor do mesmo sem que seja refletido fora da função.

			Exemplo: Suponha que seja passada por valor uma variável int a = 10 como
			parametro e durante o execução da função ocorreu alguma mudança no valor de 'a'.
			Nesse caso, fora do escopo da função continuará a = 10. Veja o arquivo:
			funcao_passagem_por_valor.c

		- Por referencia: é passado o ponteiro da variável, ou seja, passando por
		referencia, os valores alterados durante a execução de uma função são refletidos
		fora do escopo da função.

			Exemplo: Suponha que exista uma variável int a = 10 e int* pa = &a, e seja
			passada por referencia a variável 'pa' como parametro e durante o execução da
			função ocorreu alguma mudança no conteudo (*pa) de pa, ou seja, mudamos o valor
			de 'a'. Nesse caso, fora do escopo da função, o valor de 'a' será alterado. Veja
			o arquivo: funcao_passagem_por_referencia.c

			Podemos usar a passagem de parametros por referencia para salvar valores em
			outros endereços de memoria. Veja o arquivo: funcao_passagem_por_referencia_2.c

			Para que nenhum dado seja alterado acidentalmente, podemos passar ponteiros read
			only com parametros, desse modo teremos acesso ao ponteiro porém não poderemos
			alterar seu conteúdo. Para isso usamos a palvra reservada 'const'. Veja o
			arquivo: funcao_passagem_por_referencia_3.c

## Vectors (Arrays)

	Uma Array é uma forma simples de guardar uma lista de elementos. Na memória é reservado
	um espaço de memória contínuo para armazenar os elementos do Array.

	Sintaxe:

		tipo nome_do_array[]; ou tipo nome_do_array[n];

    ou, quando se sabe quais são os elementos do array:

        tipo nome_do_array[n] = {el_1, el_2, ..., el_n};

	A quantidade de elementos é um número inteiro (n) que representa quantos elementos o
	array terá. Ele é opcional.

	A indexação em C começa em 0 e vai até n-1, desse modo o primeiro elemento do array é
	acessado usando o índice 0 -> nome_do_array[0] e o último é acessado usando o índice n-1
	-> nome_do_array[n-1].

	Deve-se tomar cuidado ao acessar os elementos pois se tentarmos acessar nome_do_array[m],
	com m >= n, mesmo sabendo que não faz sentido, não dará erro de compilação e será
	retornado o conteúdo de um região memória que foi invadida pela array. Veja o arquivo:
	arrays_1.c

	Para acessar os elementos pelo índice, o SO pega o conteúdo do endereço de memória que o
	elemento ocupa. Ou seja, quando acessamos array[3], supondo que &array[3] seja 5116 e
	array[3] = 1, o que o SO faz é: array[3] = *&array[3] = *(5116) = 1.

	Imagine o seguinte array: int v[5];, nesse caso o símbolo 'v' é uma constante que
	representa o endereço inicial do vetor, de modo que ele pode ser interpretado com um
	ponteiro para v[0] -> &v = v = &v[0]. Veja o arquivo: arrays_3.c

    É possível declarar vetores multidimensionais e funcionam de forma semelhante aos vetores 1D descritos
    acima.

    Exemplos:
        - Matrizes

            tipo nome_da_matriz[][]; ou tipo nome_da_matriz[m][n];

        ou, quando se sabe quais são os elementos da matriz:

            tipo nome_da_matriz[m][n] = {
                                            {el_11, el_12, el_1n},
                                            ...,
                                            {el_m1, el_m2, ...,el_mn}
                                        };

        Quando tentamos acessar o valor de nome_da_matriz, o que de fato acontece é nome_da_matriz[0][0].

        - Tensores

            tipo nome_do_trensor[][][]; ou tipo nome_do_trensor[i][j][k];

        ou, quando se sabe quais são os elementos do tensor:

            tipo nome_do_trensor[i][j][k] = {
                                                {
                                                    {el_111, el_112, ..., el_11k},
                                                    ...,
                                                    {el_1j1, el_1j2, ..., el_1jk}
                                                },
                                                ...,
                                                {
                                                    {eli11, el_112, ..., el_i1k},
                                                    ...,
                                                    { el_ij1, el_ij2, ..., el_ijk}
                                                }
                                            };

        Quando tentamos acessar o valor de nome_do_trensor, o que de fato acontece é nome_do_trensor[0][0][0].

    Esse comportamento pode ser extendido para dimensões maiores.

## Memory allocation

    Podemos dividir a memória RAM em duas categorias principais: Stack e Heap. Geralmente a Heap
    é muito maior que a stack.

    Até o momento, estavámos vendo sobre variavéis em memória, alocação estática na Stack. Quando
    uma variável é alocada estaticamente, o espaço na memória é alocado no início da execução e ao
    final da execução o próprio SO se encarrega de limpar o espaço na memória final da execução).
    Toda varíavel é alocada na Stack.

    Existe também a possibilidade de fazer alocação dinâmica de memória, ou seja o espaço para as
    variáveis é reservado durante a execução do programa e a alocação pode ser criada e eliminada
    durante a própria execução, de modo que ocupa espaço apenas quando está sendo utilizada.
    O espaço de memória reservado na alocação dinâmica é na Heap (ou free store).
    Ao contrário da alocação estática, quando se usa alocação dinâmica, o programador é reponsável
    por desalocar a memória, porém ao final da execução do programa, o SO também desaloca, caso o
    programador não tenha desalocado, entretanto, o programador deve sempre manter o hábito de
    desalocar memória.

    Vantagens de se usar alocação dinâmica:

        - É feita em tempo de execução;
        - Não é necessário saber ao certo quanto de memória será necessário a priori;
        - Evita desperdício de espaço pois o tamanho da memória necessario é determinado conforme ncessidade.
        - Além disso, size(Heap) >> size(Stack)

    Existem pelo menos duas formas de alocar memória dinamicamente, usando as funções:

        type *var = (type *) malloc(n * sizeof(type));
    e
        type *var = (type *) calloc(n, sizeof(type));

    Essas funções recebem um valor n, que representa a quantidade de blocos de memória deve ser
    alocado, alocam a quantidade de n*size(type) na memória Heap retornam o endereço base da memória
    alocada, ou seja, a variável declarada deve ser um ponteiro do tipo type.

    Diferença entre malloc e calloc:

        - Ao alocar a memória, o malloc deixa os valores que já estavam naquelA região de memória alocada,
        ou seja, ele deixa o lixo de memória, enqaunto o calloc remove os valores existentes no espaço de
        memória e set como o zero do tipo.

    Para liberar (desalocar) a mémoria que foi alocada dinamicamente, é usada a função free(&variável), que recebe
    o endereço da variável a qual queremos desalocar.

    Assim como podemos alocar memória para um variável de um tipo primitivo, também podemos alocar memória para
    estruturas mais complexas como arrays, matrizes, structs, TAD, etc...

### Dynamic vector allocation

    Assim como na alocação de tipos primitivos, para alocar podemos usar as funções malloc e calloc.
    Da mesma forma, ele retorna o endereço base da região de memória alocada, ou seja, a variável declarada
    também deve um ponteiro (veja a seção sobre aritimética de ponteiros, deve ficar mais claro):

        type vec[] == type *vec;

    Dessa forma temos:

        type *vec = (type *) calloc(n, sifeof(type));

    Para desalocar, basta somente:

        free(vec);
        vec = NULL; -> Apontamos para NULL por boa prática de programação

### Dynamic matrix allocation

    Já para as matrizes é necessário um pouco mais de atenção, pois é necessário alocar a matriz (como um todo)
    e depois aloca os arrays internos (cada linha forma um array), ou seja:

        type **mat = (type **) calloc(m, sizeof(type *)); -> onde m = número de linhas

    logo em seguida devemos alocar cada linha da matriz:

        for(int i = 0; i < m; i++){
            type mat[i] = (type *) malloc(n, sizeof(type));  
        }

    Da mesma forma que para desalocar, devemos desalocar primeiro as linhas (cada array interno) e depois a
    matriz de fato:

        for(int i = 0; i < m; i++){
            free(mat[i]);
            mat[i] = NULL;
        }

        free(mat);
        mat = NULL;

    Essa mesma lógica deve ser seguida para tensores e array multidimensionais.

## Structs

    Struct é um pacote de variáveis que podem ter tipos diferentes. Cada variável é um campo da struct.
    Para quem é familirizado com POO, Structs podem ser vistas com uma espécie de classe, porém diferente
    das classes da Orientação a Objetos, as Structs não possuem métodos, apenas propriedades.

    Formas de definir:

        1:
            Declaração:

                struct nome_da_struct {
                    type var1;
                    type var2;
                    ...
                    type varn;
                };

            Criação de variável:

                struct nome_da_struct nome_da_variavel;

        2:
            Declaração:

                struct nome_da_struct {
                    type var1;
                    type var2;
                    ...
                    type varn;
                } [var 1, var2, ..., var3];

            Criação de variável:

                struct nome_da_struct nome_da_variavel;

            Mas nesse caso já podemos contar com as n variável já criadas no momento da definição da struct:
            var1, var2, ... varn.

        3 (Anônima):
            Declaração:

                struct {
                    type var1;
                    type var2;
                    ...
                    type var2;
                } [var 1, var2, ..., var3];

            Criação de variável:
                Não há forma de criar novas variáveis usando essa struct, apenas as criadas no momento
                da declaração da struct. Pode ser usada para definir constante ou variáveis de ambiente, etc...

        4 (Melhor forma):
            Declaração:

                typedef struct nome_da_struct {
                    type var1;
                    type var2;
                    ...
                    type var2;
                } Apelido;

            Criação de variável:

                Apelido nome_da_variavel; -> é o mesmo que struct nome_da_struct nome_da_variavel;

    Para acessar os campos de uma variável do que é derivada de um struct, existem duas formas, uma
    para structs alocadas de forma estática, outra para structs alocadas de forma dinâmica.

    Acessando os campos de variáveis derivadas de um Struct:

        typedef struct nome_da_struct {
            type var1;
            type var2;
            ...
            type varn;
        } Apelido;

        Apelido nome_da_variavel_estatica;
        Apelido nome_da_variavel_dinamica = (Apelido *) calloc(n, sizeof(Apelido));

        - Alocada de forma estática:

            nome_da_variavel_estatica.var1 = ...;
            nome_da_variavel_estatica.var2 = ...;
            ...
            nome_da_variavel_estatica.varn = ...;

        - Alocada de forma dinâmica:

            nome_da_variavel_dinamica->var1 = ...;
            nome_da_variavel_dinamica->var2 = ...;
            ...
            nome_da_variavel_dinamica->varn = ...;
