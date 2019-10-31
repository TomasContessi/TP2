
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Prefix.h"
#include "PrefixRequired.h"
/*! \file Implementation of the state machine 'prefix'
*/

/* prototypes of all internal functions */
static sc_boolean prefix_check_main_region_CERRADO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_main_region_ABIERTO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_main_region_CERRANDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_main_region_ABRIENDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_main_region_ABRIENDO_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_DEBOUNCE_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_VALIDATION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_VALIDATION_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle);
static void prefix_effect_main_region_CERRADO_tr0(Prefix* handle);
static void prefix_effect_main_region_ABIERTO_tr0(Prefix* handle);
static void prefix_effect_main_region_CERRANDO_tr0(Prefix* handle);
static void prefix_effect_main_region_ABRIENDO_tr0(Prefix* handle);
static void prefix_effect_main_region_ABRIENDO_tr1(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr0(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr1(Prefix* handle);
static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_TECX_DEBOUNCE_tr0(Prefix* handle);
static void prefix_effect_TECX_VALIDATION_tr0(Prefix* handle);
static void prefix_effect_TECX_VALIDATION_tr1(Prefix* handle);
static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle);
static void prefix_enact_main_region_CERRADO(Prefix* handle);
static void prefix_enact_main_region_ABIERTO(Prefix* handle);
static void prefix_enact_main_region_CERRANDO(Prefix* handle);
static void prefix_enact_main_region_ABRIENDO(Prefix* handle);
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle);
static void prefix_exact_main_region_CERRANDO(Prefix* handle);
static void prefix_exact_main_region_ABRIENDO(Prefix* handle);
static void prefix_exact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_enseq_main_region_CERRADO_default(Prefix* handle);
static void prefix_enseq_main_region_ABIERTO_default(Prefix* handle);
static void prefix_enseq_main_region_CERRANDO_default(Prefix* handle);
static void prefix_enseq_main_region_ABRIENDO_default(Prefix* handle);
static void prefix_enseq_IDLE_ESPERA_default(Prefix* handle);
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle);
static void prefix_enseq_TECX_VALIDATION_default(Prefix* handle);
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_main_region_default(Prefix* handle);
static void prefix_enseq_IDLE_default(Prefix* handle);
static void prefix_enseq_TECX_default(Prefix* handle);
static void prefix_exseq_main_region_CERRADO(Prefix* handle);
static void prefix_exseq_main_region_ABIERTO(Prefix* handle);
static void prefix_exseq_main_region_CERRANDO(Prefix* handle);
static void prefix_exseq_main_region_ABRIENDO(Prefix* handle);
static void prefix_exseq_IDLE_ESPERA(Prefix* handle);
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle);
static void prefix_exseq_TECX_VALIDATION(Prefix* handle);
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle);
static void prefix_exseq_main_region(Prefix* handle);
static void prefix_exseq_IDLE(Prefix* handle);
static void prefix_exseq_TECX(Prefix* handle);
static void prefix_react_main_region_CERRADO(Prefix* handle);
static void prefix_react_main_region_ABIERTO(Prefix* handle);
static void prefix_react_main_region_CERRANDO(Prefix* handle);
static void prefix_react_main_region_ABRIENDO(Prefix* handle);
static void prefix_react_IDLE_ESPERA(Prefix* handle);
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_react_TECX_DEBOUNCE(Prefix* handle);
static void prefix_react_TECX_VALIDATION(Prefix* handle);
static void prefix_react_TECX_OPRIMIDO(Prefix* handle);
static void prefix_react_main_region__entry_Default(Prefix* handle);
static void prefix_react_IDLE__entry_Default(Prefix* handle);
static void prefix_react_TECX__entry_Default(Prefix* handle);
static void prefix_clearInEvents(Prefix* handle);
static void prefix_clearOutEvents(Prefix* handle);

const sc_integer PREFIX_PREFIXIFACE_LED3 = 5;
const sc_boolean PREFIX_PREFIXIFACE_LED_ON = bool_false;
const sc_boolean PREFIX_PREFIXIFACE_LED_OFF = bool_true;
const sc_integer PREFIX_PREFIXIFACE_TEC1 = 1;
const sc_integer PREFIX_PREFIXIFACE_TEC2 = 2;
const sc_integer PREFIX_PREFIXIFACE_TEC3 = 3;
const sc_integer PREFIX_PREFIXIFACE_TEC4 = 4;

void prefix_init(Prefix* handle)
{
	sc_integer i;

	for (i = 0; i < PREFIX_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Prefix_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	prefix_clearInEvents(handle);
	prefix_clearOutEvents(handle);

	/* Default init sequence for statechart prefix */
	handle->internal.viTecla = 0;
	handle->internal.viFrec = 0;
	handle->internal.viTension = 0;

}

void prefix_enter(Prefix* handle)
{
	/* Default enter sequence for statechart prefix */
	prefix_enseq_main_region_default(handle);
	prefix_enseq_IDLE_default(handle);
	prefix_enseq_TECX_default(handle);
}

void prefix_exit(Prefix* handle)
{
	/* Default exit sequence for statechart prefix */
	prefix_exseq_main_region(handle);
	prefix_exseq_IDLE(handle);
	prefix_exseq_TECX(handle);
}

sc_boolean prefix_isActive(const Prefix* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Prefix_last_state || handle->stateConfVector[1] != Prefix_last_state || handle->stateConfVector[2] != Prefix_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean prefix_isFinal(const Prefix* handle)
{
   return bool_false;
}

static void prefix_clearInEvents(Prefix* handle)
{
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->iface.evTurnOn_raised = bool_false;
	handle->iface.evTurnOff_raised = bool_false;
	handle->iface.evForma_raised = bool_false;
	handle->iface.evMagn_raised = bool_false;
	handle->iface.A_raised = bool_false;
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.siTitilarLED_raised = bool_false;
	handle->internal.siNoTitilarLED_raised = bool_false;
	handle->internal.siAbrir_raised = bool_false;
	handle->internal.siCerrar_raised = bool_false;
	handle->internal.siUp_raised = bool_false;
	handle->internal.siDown_raised = bool_false;
	handle->timeEvents.prefix_main_region_CERRANDO_tev0_raised = bool_false;
	handle->timeEvents.prefix_main_region_ABRIENDO_tev0_raised = bool_false;
	handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised = bool_false;
}

static void prefix_clearOutEvents(Prefix* handle)
{
}

void prefix_runCycle(Prefix* handle)
{
	
	prefix_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < PREFIX_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Prefix_main_region_CERRADO :
		{
			prefix_react_main_region_CERRADO(handle);
			break;
		}
		case Prefix_main_region_ABIERTO :
		{
			prefix_react_main_region_ABIERTO(handle);
			break;
		}
		case Prefix_main_region_CERRANDO :
		{
			prefix_react_main_region_CERRANDO(handle);
			break;
		}
		case Prefix_main_region_ABRIENDO :
		{
			prefix_react_main_region_ABRIENDO(handle);
			break;
		}
		case Prefix_IDLE_ESPERA :
		{
			prefix_react_IDLE_ESPERA(handle);
			break;
		}
		case Prefix_TECX_NO_OPRIMIDO :
		{
			prefix_react_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_DEBOUNCE :
		{
			prefix_react_TECX_DEBOUNCE(handle);
			break;
		}
		case Prefix_TECX_VALIDATION :
		{
			prefix_react_TECX_VALIDATION(handle);
			break;
		}
		case Prefix_TECX_OPRIMIDO :
		{
			prefix_react_TECX_OPRIMIDO(handle);
			break;
		}
		default:
			break;
		}
	}
	
	prefix_clearInEvents(handle);
}

void prefix_raiseTimeEvent(const Prefix* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(PrefixTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Prefix_main_region_CERRADO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_main_region_CERRADO
			);
			break;
		case Prefix_main_region_ABIERTO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_main_region_ABIERTO
			);
			break;
		case Prefix_main_region_CERRANDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_main_region_CERRANDO
			);
			break;
		case Prefix_main_region_ABRIENDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_main_region_ABRIENDO
			);
			break;
		case Prefix_IDLE_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_IDLE_ESPERA
			);
			break;
		case Prefix_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_TECX_NO_OPRIMIDO
			);
			break;
		case Prefix_TECX_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_TECX_DEBOUNCE
			);
			break;
		case Prefix_TECX_VALIDATION :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_TECX_VALIDATION
			);
			break;
		case Prefix_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_TECX_OPRIMIDO
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void prefixIface_raise_evTECXOprimido(Prefix* handle, sc_integer value)
{
	handle->iface.evTECXOprimido_value = value;
	handle->iface.evTECXOprimido_raised = bool_true;
}
void prefixIface_raise_evTECXNoOprimido(Prefix* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_true;
}
void prefixIface_raise_evTurnOn(Prefix* handle)
{
	handle->iface.evTurnOn_raised = bool_true;
}
void prefixIface_raise_evTurnOff(Prefix* handle)
{
	handle->iface.evTurnOff_raised = bool_true;
}
void prefixIface_raise_evForma(Prefix* handle)
{
	handle->iface.evForma_raised = bool_true;
}
void prefixIface_raise_evMagn(Prefix* handle)
{
	handle->iface.evMagn_raised = bool_true;
}
void prefixIface_raise_a(Prefix* handle)
{
	handle->iface.A_raised = bool_true;
}


const sc_integer prefixIface_get_lED3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED3;
}
const sc_boolean prefixIface_get_lED_ON(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED_ON;
}
const sc_boolean prefixIface_get_lED_OFF(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED_OFF;
}
const sc_integer prefixIface_get_tEC1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC1;
}
const sc_integer prefixIface_get_tEC2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC2;
}
const sc_integer prefixIface_get_tEC3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC3;
}
const sc_integer prefixIface_get_tEC4(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC4;
}

/* implementations of all internal functions */

static sc_boolean prefix_check_main_region_CERRADO_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siAbrir_raised;
}

static sc_boolean prefix_check_main_region_ABIERTO_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siCerrar_raised;
}

static sc_boolean prefix_check_main_region_CERRANDO_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_main_region_CERRANDO_tev0_raised;
}

static sc_boolean prefix_check_main_region_ABRIENDO_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_main_region_ABRIENDO_tev0_raised;
}

static sc_boolean prefix_check_main_region_ABRIENDO_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siCerrar_raised;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC1)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr1_tr1(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC2)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean prefix_check_TECX_DEBOUNCE_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised;
}

static sc_boolean prefix_check_TECX_VALIDATION_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean prefix_check_TECX_VALIDATION_tr1_tr1(const Prefix* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static void prefix_effect_main_region_CERRADO_tr0(Prefix* handle)
{
	prefix_exseq_main_region_CERRADO(handle);
	prefix_enseq_main_region_ABRIENDO_default(handle);
}

static void prefix_effect_main_region_ABIERTO_tr0(Prefix* handle)
{
	prefix_exseq_main_region_ABIERTO(handle);
	prefix_enseq_main_region_CERRANDO_default(handle);
}

static void prefix_effect_main_region_CERRANDO_tr0(Prefix* handle)
{
	prefix_exseq_main_region_CERRANDO(handle);
	prefix_enseq_main_region_CERRADO_default(handle);
}

static void prefix_effect_main_region_ABRIENDO_tr0(Prefix* handle)
{
	prefix_exseq_main_region_ABRIENDO(handle);
	prefix_enseq_main_region_ABIERTO_default(handle);
}

static void prefix_effect_main_region_ABRIENDO_tr1(Prefix* handle)
{
	prefix_exseq_main_region_ABRIENDO(handle);
	prefix_enseq_main_region_CERRANDO_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr0(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siCerrar_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr1(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siAbrir_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_TECX_NO_OPRIMIDO(handle);
	prefix_enseq_TECX_DEBOUNCE_default(handle);
}

static void prefix_effect_TECX_DEBOUNCE_tr0(Prefix* handle)
{
	prefix_exseq_TECX_DEBOUNCE(handle);
	prefix_enseq_TECX_VALIDATION_default(handle);
}

static void prefix_effect_TECX_VALIDATION_tr0(Prefix* handle)
{
	prefix_exseq_TECX_VALIDATION(handle);
	prefix_enseq_TECX_OPRIMIDO_default(handle);
}

static void prefix_effect_TECX_VALIDATION_tr1(Prefix* handle)
{
	prefix_exseq_TECX_VALIDATION(handle);
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_TECX_OPRIMIDO(handle);
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

/* Entry action for state 'CERRADO'. */
static void prefix_enact_main_region_CERRADO(Prefix* handle)
{
	/* Entry action for state 'CERRADO'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'ABIERTO'. */
static void prefix_enact_main_region_ABIERTO(Prefix* handle)
{
	/* Entry action for state 'ABIERTO'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'CERRANDO'. */
static void prefix_enact_main_region_CERRANDO(Prefix* handle)
{
	/* Entry action for state 'CERRANDO'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_main_region_CERRANDO_tev0_raised) , 500, bool_false);
}

/* Entry action for state 'ABRIENDO'. */
static void prefix_enact_main_region_ABRIENDO(Prefix* handle)
{
	/* Entry action for state 'ABRIENDO'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_main_region_ABRIENDO_tev0_raised) , 500, bool_false);
}

/* Entry action for state 'DEBOUNCE'. */
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised) , 50, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Exit action for state 'CERRANDO'. */
static void prefix_exact_main_region_CERRANDO(Prefix* handle)
{
	/* Exit action for state 'CERRANDO'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_main_region_CERRANDO_tev0_raised) );		
}

/* Exit action for state 'ABRIENDO'. */
static void prefix_exact_main_region_ABRIENDO(Prefix* handle)
{
	/* Exit action for state 'ABRIENDO'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_main_region_ABRIENDO_tev0_raised) );		
}

/* Exit action for state 'DEBOUNCE'. */
static void prefix_exact_TECX_DEBOUNCE(Prefix* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised) );		
}

/* 'default' enter sequence for state CERRADO */
static void prefix_enseq_main_region_CERRADO_default(Prefix* handle)
{
	/* 'default' enter sequence for state CERRADO */
	prefix_enact_main_region_CERRADO(handle);
	handle->stateConfVector[0] = Prefix_main_region_CERRADO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ABIERTO */
static void prefix_enseq_main_region_ABIERTO_default(Prefix* handle)
{
	/* 'default' enter sequence for state ABIERTO */
	prefix_enact_main_region_ABIERTO(handle);
	handle->stateConfVector[0] = Prefix_main_region_ABIERTO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state CERRANDO */
static void prefix_enseq_main_region_CERRANDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state CERRANDO */
	prefix_enact_main_region_CERRANDO(handle);
	handle->stateConfVector[0] = Prefix_main_region_CERRANDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ABRIENDO */
static void prefix_enseq_main_region_ABRIENDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state ABRIENDO */
	prefix_enact_main_region_ABRIENDO(handle);
	handle->stateConfVector[0] = Prefix_main_region_ABRIENDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ESPERA */
static void prefix_enseq_IDLE_ESPERA_default(Prefix* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[1] = Prefix_IDLE_ESPERA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[2] = Prefix_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state DEBOUNCE */
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	prefix_enact_TECX_DEBOUNCE(handle);
	handle->stateConfVector[2] = Prefix_TECX_DEBOUNCE;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state VALIDATION */
static void prefix_enseq_TECX_VALIDATION_default(Prefix* handle)
{
	/* 'default' enter sequence for state VALIDATION */
	handle->stateConfVector[2] = Prefix_TECX_VALIDATION;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state OPRIMIDO */
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	prefix_enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[2] = Prefix_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for region main region */
static void prefix_enseq_main_region_default(Prefix* handle)
{
	/* 'default' enter sequence for region main region */
	prefix_react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region IDLE */
static void prefix_enseq_IDLE_default(Prefix* handle)
{
	/* 'default' enter sequence for region IDLE */
	prefix_react_IDLE__entry_Default(handle);
}

/* 'default' enter sequence for region TECX */
static void prefix_enseq_TECX_default(Prefix* handle)
{
	/* 'default' enter sequence for region TECX */
	prefix_react_TECX__entry_Default(handle);
}

/* Default exit sequence for state CERRADO */
static void prefix_exseq_main_region_CERRADO(Prefix* handle)
{
	/* Default exit sequence for state CERRADO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ABIERTO */
static void prefix_exseq_main_region_ABIERTO(Prefix* handle)
{
	/* Default exit sequence for state ABIERTO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state CERRANDO */
static void prefix_exseq_main_region_CERRANDO(Prefix* handle)
{
	/* Default exit sequence for state CERRANDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
	prefix_exact_main_region_CERRANDO(handle);
}

/* Default exit sequence for state ABRIENDO */
static void prefix_exseq_main_region_ABRIENDO(Prefix* handle)
{
	/* Default exit sequence for state ABRIENDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
	prefix_exact_main_region_ABRIENDO(handle);
}

/* Default exit sequence for state ESPERA */
static void prefix_exseq_IDLE_ESPERA(Prefix* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state NO_OPRIMIDO */
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state DEBOUNCE */
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
	prefix_exact_TECX_DEBOUNCE(handle);
}

/* Default exit sequence for state VALIDATION */
static void prefix_exseq_TECX_VALIDATION(Prefix* handle)
{
	/* Default exit sequence for state VALIDATION */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state OPRIMIDO */
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for region main region */
static void prefix_exseq_main_region(Prefix* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of prefix.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Prefix_main_region_CERRADO :
		{
			prefix_exseq_main_region_CERRADO(handle);
			break;
		}
		case Prefix_main_region_ABIERTO :
		{
			prefix_exseq_main_region_ABIERTO(handle);
			break;
		}
		case Prefix_main_region_CERRANDO :
		{
			prefix_exseq_main_region_CERRANDO(handle);
			break;
		}
		case Prefix_main_region_ABRIENDO :
		{
			prefix_exseq_main_region_ABRIENDO(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region IDLE */
static void prefix_exseq_IDLE(Prefix* handle)
{
	/* Default exit sequence for region IDLE */
	/* Handle exit of all possible states (of prefix.IDLE) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Prefix_IDLE_ESPERA :
		{
			prefix_exseq_IDLE_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region TECX */
static void prefix_exseq_TECX(Prefix* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of prefix.TECX) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_TECX_NO_OPRIMIDO :
		{
			prefix_exseq_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_DEBOUNCE :
		{
			prefix_exseq_TECX_DEBOUNCE(handle);
			break;
		}
		case Prefix_TECX_VALIDATION :
		{
			prefix_exseq_TECX_VALIDATION(handle);
			break;
		}
		case Prefix_TECX_OPRIMIDO :
		{
			prefix_exseq_TECX_OPRIMIDO(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state CERRADO. */
static void prefix_react_main_region_CERRADO(Prefix* handle)
{
	/* The reactions of state CERRADO. */
	if (prefix_check_main_region_CERRADO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_main_region_CERRADO_tr0(handle);
	} 
}

/* The reactions of state ABIERTO. */
static void prefix_react_main_region_ABIERTO(Prefix* handle)
{
	/* The reactions of state ABIERTO. */
	if (prefix_check_main_region_ABIERTO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_main_region_ABIERTO_tr0(handle);
	} 
}

/* The reactions of state CERRANDO. */
static void prefix_react_main_region_CERRANDO(Prefix* handle)
{
	/* The reactions of state CERRANDO. */
	if (prefix_check_main_region_CERRANDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_main_region_CERRANDO_tr0(handle);
	} 
}

/* The reactions of state ABRIENDO. */
static void prefix_react_main_region_ABRIENDO(Prefix* handle)
{
	/* The reactions of state ABRIENDO. */
	if (prefix_check_main_region_ABRIENDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_main_region_ABRIENDO_tr0(handle);
	}  else
	{
		if (prefix_check_main_region_ABRIENDO_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_main_region_ABRIENDO_tr1(handle);
		} 
	}
}

/* The reactions of state ESPERA. */
static void prefix_react_IDLE_ESPERA(Prefix* handle)
{
	/* The reactions of state ESPERA. */
	if (prefix_check_IDLE_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_IDLE_ESPERA_tr0(handle);
	}  else
	{
		if (prefix_check_IDLE_ESPERA_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_IDLE_ESPERA_tr1(handle);
		} 
	}
}

/* The reactions of state NO_OPRIMIDO. */
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state DEBOUNCE. */
static void prefix_react_TECX_DEBOUNCE(Prefix* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (prefix_check_TECX_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state VALIDATION. */
static void prefix_react_TECX_VALIDATION(Prefix* handle)
{
	/* The reactions of state VALIDATION. */
	if (prefix_check_TECX_VALIDATION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_VALIDATION_tr0(handle);
	}  else
	{
		if (prefix_check_TECX_VALIDATION_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_TECX_VALIDATION_tr1(handle);
		} 
	}
}

/* The reactions of state OPRIMIDO. */
static void prefix_react_TECX_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (prefix_check_TECX_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_OPRIMIDO_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void prefix_react_main_region__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_main_region_CERRADO_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_IDLE__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_IDLE_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_TECX__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}


