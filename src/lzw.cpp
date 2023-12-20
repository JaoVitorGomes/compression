#include <unordered_map>
using namespace std;

#include "lzw.h"

namespace Compression
{
    LZW::LZW()
    {
    }

    std::vector<int> LZW::compress(const string& input)
    {

        std::vector<int> codes;
        unordered_map<string, int> dictionary;

        // 0. Inicialize o dicionário com todas os 255 símbolos da fonte
        // 1. index = 256
        // 2. Inicialize string prefixo com a primeira letra do input
        // 3. Enquanto houver caracter c do input para processar
        //   3.1 Se prefixo + c não está no dicionário
        //     3.1.1 Obter código p de prefixo do dicionário
        //     3.1.2 Adcionar p ao vetor de códigos
        //     3.1.3 Adcionar prefixo + c no dicionário com indice index
        //     3.1.5 index = index + 1
        //     3.1.6 Reinicialize prefixo com c
        //   3.2 Caso contrário,
        //     3.2.1 prefixo = prefixo + c
        // 4. Se prefixo não estiver vazio
        //   4.1  Obter código p de prefixo do dicionário
        //   4.2  Adcionar p ao vetor de códigos
        // 5. Retornar o vetor de códigos.
    
        return codes;

    }

    string LZW::decompress(std::vector<int> &codes)
    {

        std::unordered_map<int,string> dictionary;
        std::string output = "";

        // 0. Inicialize o dicionário com todas os 255 símbolos da fonte
        // 1. Inicialize a string de saida com vazio
        // 2. Inicialize index com 256
        // 3. Seja p  o primeiro código do vetor
        // 4. Obter string str do dicionario referente ao código p
        // 5. Concatenar str na string de saida
        // 6. Enquanto houver códigos a decodificar
        //  6.1 Seja n o proximo codigo
        //  6.2 Seja str uma string vazia
        //  6.2 Se o codigo n está no dicionário
        //  6.2.1  str = dictionary[p];
        //  6.3 caso contrário
        //  6.3.1  str = dictionary[p] + dictionary[p][0];
        //  6.4 Concatenar str na string de saida
        //  6.5 Adiciona a dictionary[p] + currentString[0] ao dicionario na posição index
        //  6.6 index = index + 1
        //  6.7 p = n
        // 7. retorna string de saida
        
        return output;
    }
}

