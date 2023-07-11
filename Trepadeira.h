#include "Obstaculo.h"

namespace Entidades
{
    class Trepadeira: public Obstaculo
    {
    private:
        bool espinhosa;

        public:
            Trepadeira(float x, float y);
            ~Trepadeira();
            const bool getEspinhosa();
    };
}