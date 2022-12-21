#ifndef E0A52444_98EA_472E_8779_494CD3D43CD4
#define E0A52444_98EA_472E_8779_494CD3D43CD4
#include "common.h"
typedef enum
{
    EXIT_modeLowTrigger,
    EXIT_modeFallingEdgeTrigger
} EXIT_mode;

void externalInterruptConfig(uint8_t extiNum, EXIT_mode mode, void (*callback)(void));

#endif /* E0A52444_98EA_472E_8779_494CD3D43CD4 */
