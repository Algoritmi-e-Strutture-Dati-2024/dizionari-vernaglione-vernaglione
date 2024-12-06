#include <iostream>

template <typename T>
class DizionarioEsteso {
private:
    static const int TABLE_SIZE = 100; // Dimensione fissa della tabella hash
    struct Entry {
        std::string key;
        T value;
        bool isOccupied = false;
    };

    Entry table[TABLE_SIZE];

    // Funzione hash di base
   int hashFunction(const std::string& key) const {
    int hash = 0;
    for (char ch : key) {
        hash += static_cast<int>(ch);
    }
    return hash % TABLE_SIZE;
}

//ESERCIZIO 2




int findSlot (int index) const{
	 int memIndex = index;  // Memorizza l'indice iniziale
	 
	 
	while(table[index].isOccupied == true) //controllo 
	{
		index ++;
	}
	return index; //restituisce l indice della posizione libera
}







public:
    // Metodo per aggiungere una coppia chiave-valore
    void inserisci(const std::string key, const T value) {
        int index = hashFunction(key);

        if (table[index].isOccupied) {
            std::cerr << "Collision detected for key: " << key << " at index " << index << ". Not handling collisions.\n";
            index = findSlot(index);
            if (index == -1)
			 {
            std::cerr << "Unable to insert: Hash table is full!\n";
            
            return;  // La tabella è piena, quindi non possiamo inserire
        }
      }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
    }
    
    
    
    
    //Metodo per cancellare una coppia dato il valore della chiave
    void rimuovi(const std::string key, const T value) {
    	int index = hashFunction(key);
    	
    	if(table[index].isOccupied && table[index].key != key)
    	{
    	 std:: cerr <<"Collision detected,resolving...\n";
		 index= findSlot(index);	
		}
    	

        if (table[index].isOccupied = true ) 
		{
         // Rimuove la coppia chiave-valore
            table[index].isOccupied = false;  // Segna la posizione come vuota
        }
      }
    

    // Metodo per ottenere il valore associato a una chiave
    T recupera(const std::string key) const {
        int index = hashFunction(key);

if(table[index].isOccupied && table[index].key != key)
    	{
    	 std:: cerr <<"Collision detected,resolving...\n";
		 index= findSlot(index);	
		}

        if (table[index].isOccupied && table[index].key == key) {
            return table[index].value;
        }

        return "Key not found!";
    }


//Metodo per Verificare se una chiave è presente nel dizionario.

bool Findkey(const std::string key) const {
	int index = hashFunction(key);
	
	if(table[index].isOccupied && table[index].key != key)
    	{
    	 std:: cerr <<"Collision detected,resolving...\n";
		 index= findSlot(index);	
		}
	
	 if (table[index].isOccupied == key) {
            return true;
        }

        return false;
	}


    // Metodo per stampare il contenuto del dizionario
    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Index " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }
    
    
    
    
    
