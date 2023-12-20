

#include "lz78.h"

namespace Compression 
{

    // TODO: Implementar a compressão do método LZ78 seguindo os passos abaixo.
 std::vector<code> LZ78::compress(const std::string& input)
{
    std::unordered_map<std::string, int> dictionary;
    std::vector<code> output;

    std::string prefix = "";  
    int index = 0; 

    for (char c : input) 
    {
        std::string prefixPlusC = prefix + c;
        if (dictionary.find(prefixPlusC) == dictionary.end())  
        {
            int p = dictionary[prefix];  
            output.push_back({p, c});  
            index = index + 1;  
            dictionary[prefixPlusC] = index; 
            prefix = "";  
        }
        else 
        {
            prefix = prefixPlusC; 
        }
    }

    if (!prefix.empty())  
    {
        int p = dictionary[prefix];
        output.push_back({p, '\0'}); 
    }

    return output;
}


    std::string LZ78::decompress( std::vector<code>& compressed)
    {
        // Para a descompressão usamos um dicionário inverso.
        std::unordered_map<int, string> dictionary;
        std::string decompressed = "";
        int index = 0;
        int pos = 0;

        // cada iteração dessa laço, process um código com
        // a seguinte formatação <int,char>
        while(pos < compressed.size())
        {
            // recupera codigo e caracter
            int p = compressed[pos].p;
            char c = compressed[pos].c;
            
            std::string prefix = "";
            
            // Recupera o prefixo no dicionário
            if (p != 0) {
                prefix += dictionary[p];
            }
            
            prefix             += c;

            // escreve prefix + c na saida
            decompressed       += prefix;

            // incrementa indice 
            index = index + 1;

            // adiciona prefix + c no dicionáriona posição index
            dictionary[index] = prefix;

            pos++; 

        }

    
        return decompressed;
    }
    

    void LZ78::print_codes(std::vector<code> & codes)
    {
        for(int i = 0; i < codes.size(); i++)
            cout << "<" << to_string(codes[i].p) <<","<<codes[i].c <<">";
        cout << endl;
    }
    
}
