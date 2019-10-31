
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Prefix.h"
#include "PrefixRequired.h"
/*! \file Implementation of the state machine 'prefix'
*/

/* prototypes of all internal functions */
static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_DEBOUNCE_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_VALIDATION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_VALIDATION_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_IDLE_ESPERA_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_MODO_NORMAL_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_MODO_GRILL_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_MODO_DESCONGELAR_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_MICROONDAS_APAGADO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_MICROONDAS_ENCENDIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_MICROONDAS_ENCENDIDO_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_MICROONDAS_ENCENDIDO_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LED2_Reposo_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED2_Titala_UP_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED2_Titala_UP_r1_Apagado_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED2_Titala_UP_r1_Encendido_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED3_Reposo_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED3_Titila_Tension_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED3_Titila_Tension_r1_Apagado_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED3_Titila_Tension_r1_Encendido_tr0_tr0(const Prefix* handle);
static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_TECX_DEBOUNCE_tr0(Prefix* handle);
static void prefix_effect_TECX_VALIDATION_tr0(Prefix* handle);
static void prefix_effect_TECX_VALIDATION_tr1(Prefix* handle);
static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr0(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr1(Prefix* handle);
static void prefix_effect_IDLE_ESPERA_tr2(Prefix* handle);
static void prefix_effect_MODO_NORMAL_tr0(Prefix* handle);
static void prefix_effect_MODO_GRILL_tr0(Prefix* handle);
static void prefix_effect_MODO_DESCONGELAR_tr0(Prefix* handle);
static void prefix_effect_MICROONDAS_APAGADO_tr0(Prefix* handle);
static void prefix_effect_MICROONDAS_ENCENDIDO_tr0(Prefix* handle);
static void prefix_effect_MICROONDAS_ENCENDIDO_tr1(Prefix* handle);
static void prefix_effect_MICROONDAS_ENCENDIDO_tr2(Prefix* handle);
static void prefix_effect_LED2_Reposo_tr0(Prefix* handle);
static void prefix_effect_LED2_Titala_UP_tr0(Prefix* handle);
static void prefix_effect_LED2_Titala_UP_r1_Apagado_tr0(Prefix* handle);
static void prefix_effect_LED2_Titala_UP_r1_Encendido_tr0(Prefix* handle);
static void prefix_effect_LED3_Reposo_tr0(Prefix* handle);
static void prefix_effect_LED3_Titila_Tension_tr0(Prefix* handle);
static void prefix_effect_LED3_Titila_Tension_r1_Apagado_tr0(Prefix* handle);
static void prefix_effect_LED3_Titila_Tension_r1_Encendido_tr0(Prefix* handle);
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle);
static void prefix_enact_MODO_NORMAL(Prefix* handle);
static void prefix_enact_MODO_GRILL(Prefix* handle);
static void prefix_enact_MODO_DESCONGELAR(Prefix* handle);
static void prefix_enact_MICROONDAS_APAGADO(Prefix* handle);
static void prefix_enact_MICROONDAS_ENCENDIDO(Prefix* handle);
static void prefix_enact_LED2_Reposo(Prefix* handle);
static void prefix_enact_LED2_Titala_UP(Prefix* handle);
static void prefix_enact_LED2_Titala_UP_r1_Apagado(Prefix* handle);
static void prefix_enact_LED2_Titala_UP_r1_Encendido(Prefix* handle);
static void prefix_enact_LED3_Reposo(Prefix* handle);
static void prefix_enact_LED3_Titila_Tension_r1_Apagado(Prefix* handle);
static void prefix_enact_LED3_Titila_Tension_r1_Encendido(Prefix* handle);
static void prefix_exact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_exact_MICROONDAS_ENCENDIDO(Prefix* handle);
static void prefix_exact_LED2_Titala_UP(Prefix* handle);
static void prefix_exact_LED2_Titala_UP_r1_Apagado(Prefix* handle);
static void prefix_exact_LED2_Titala_UP_r1_Encendido(Prefix* handle);
static void prefix_exact_LED3_Titila_Tension_r1_Apagado(Prefix* handle);
static void prefix_exact_LED3_Titila_Tension_r1_Encendido(Prefix* handle);
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle);
static void prefix_enseq_TECX_VALIDATION_default(Prefix* handle);
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_IDLE_ESPERA_default(Prefix* handle);
static void prefix_enseq_MODO_NORMAL_default(Prefix* handle);
static void prefix_enseq_MODO_GRILL_default(Prefix* handle);
static void prefix_enseq_MODO_DESCONGELAR_default(Prefix* handle);
static void prefix_enseq_MICROONDAS_APAGADO_default(Prefix* handle);
static void prefix_enseq_MICROONDAS_ENCENDIDO_default(Prefix* handle);
static void prefix_enseq_LED2_Reposo_default(Prefix* handle);
static void prefix_enseq_LED2_Titala_UP_default(Prefix* handle);
static void prefix_enseq_LED2_Titala_UP_r1_Apagado_default(Prefix* handle);
static void prefix_enseq_LED2_Titala_UP_r1_Encendido_default(Prefix* handle);
static void prefix_enseq_LED3_Reposo_default(Prefix* handle);
static void prefix_enseq_LED3_Titila_Tension_default(Prefix* handle);
static void prefix_enseq_LED3_Titila_Tension_r1_Apagado_default(Prefix* handle);
static void prefix_enseq_LED3_Titila_Tension_r1_Encendido_default(Prefix* handle);
static void prefix_enseq_TECX_default(Prefix* handle);
static void prefix_enseq_IDLE_default(Prefix* handle);
static void prefix_enseq_MODO_default(Prefix* handle);
static void prefix_enseq_MICROONDAS_default(Prefix* handle);
static void prefix_enseq_LED2_default(Prefix* handle);
static void prefix_enseq_LED2_Titala_UP_r1_default(Prefix* handle);
static void prefix_enseq_LED3_default(Prefix* handle);
static void prefix_enseq_LED3_Titila_Tension_r1_default(Prefix* handle);
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle);
static void prefix_exseq_TECX_VALIDATION(Prefix* handle);
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle);
static void prefix_exseq_IDLE_ESPERA(Prefix* handle);
static void prefix_exseq_MODO_NORMAL(Prefix* handle);
static void prefix_exseq_MODO_GRILL(Prefix* handle);
static void prefix_exseq_MODO_DESCONGELAR(Prefix* handle);
static void prefix_exseq_MICROONDAS_APAGADO(Prefix* handle);
static void prefix_exseq_MICROONDAS_ENCENDIDO(Prefix* handle);
static void prefix_exseq_LED2_Reposo(Prefix* handle);
static void prefix_exseq_LED2_Titala_UP(Prefix* handle);
static void prefix_exseq_LED2_Titala_UP_r1_Apagado(Prefix* handle);
static void prefix_exseq_LED2_Titala_UP_r1_Encendido(Prefix* handle);
static void prefix_exseq_LED3_Reposo(Prefix* handle);
static void prefix_exseq_LED3_Titila_Tension(Prefix* handle);
static void prefix_exseq_LED3_Titila_Tension_r1_Apagado(Prefix* handle);
static void prefix_exseq_LED3_Titila_Tension_r1_Encendido(Prefix* handle);
static void prefix_exseq_TECX(Prefix* handle);
static void prefix_exseq_IDLE(Prefix* handle);
static void prefix_exseq_MODO(Prefix* handle);
static void prefix_exseq_MICROONDAS(Prefix* handle);
static void prefix_exseq_LED2(Prefix* handle);
static void prefix_exseq_LED2_Titala_UP_r1(Prefix* handle);
static void prefix_exseq_LED3(Prefix* handle);
static void prefix_exseq_LED3_Titila_Tension_r1(Prefix* handle);
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_react_TECX_DEBOUNCE(Prefix* handle);
static void prefix_react_TECX_VALIDATION(Prefix* handle);
static void prefix_react_TECX_OPRIMIDO(Prefix* handle);
static void prefix_react_IDLE_ESPERA(Prefix* handle);
static void prefix_react_MODO_NORMAL(Prefix* handle);
static void prefix_react_MODO_GRILL(Prefix* handle);
static void prefix_react_MODO_DESCONGELAR(Prefix* handle);
static void prefix_react_MICROONDAS_APAGADO(Prefix* handle);
static void prefix_react_MICROONDAS_ENCENDIDO(Prefix* handle);
static void prefix_react_LED2_Reposo(Prefix* handle);
static void prefix_react_LED2_Titala_UP_r1_Apagado(Prefix* handle);
static void prefix_react_LED2_Titala_UP_r1_Encendido(Prefix* handle);
static void prefix_react_LED3_Reposo(Prefix* handle);
static void prefix_react_LED3_Titila_Tension_r1_Apagado(Prefix* handle);
static void prefix_react_LED3_Titila_Tension_r1_Encendido(Prefix* handle);
static void prefix_react_TECX__entry_Default(Prefix* handle);
static void prefix_react_IDLE__entry_Default(Prefix* handle);
static void prefix_react_MODO__entry_Default(Prefix* handle);
static void prefix_react_MICROONDAS__entry_Default(Prefix* handle);
static void prefix_react_LED2__entry_Default(Prefix* handle);
static void prefix_react_LED2_Titala_UP_r1__entry_Default(Prefix* handle);
static void prefix_react_LED3__entry_Default(Prefix* handle);
static void prefix_react_LED3_Titila_Tension_r1__entry_Default(Prefix* handle);
static void prefix_clearInEvents(Prefix* handle);
static void prefix_clearOutEvents(Prefix* handle);

const sc_integer PREFIX_PREFIXIFACE_LEDR = 0;
const sc_integer PREFIX_PREFIXIFACE_LEDG = 1;
const sc_integer PREFIX_PREFIXIFACE_LEDB = 2;
const sc_integer PREFIX_PREFIXIFACE_LED1 = 3;
const sc_integer PREFIX_PREFIXIFACE_LED2 = 4;
const sc_integer PREFIX_PREFIXIFACE_LED3 = 5;
const sc_boolean PREFIX_PREFIXIFACE_LED_ON = bool_true;
const sc_boolean PREFIX_PREFIXIFACE_LED_OFF = bool_false;
const sc_integer PREFIX_PREFIXIFACE_TEC1 = 1 << 0;
const sc_integer PREFIX_PREFIXIFACE_TEC2 = 1 << 1;
const sc_integer PREFIX_PREFIXIFACE_TEC3 = 1 << 2;
const sc_integer PREFIX_PREFIXIFACE_TEC4 = 1 << 3;

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

}

void prefix_enter(Prefix* handle)
{
	/* Default enter sequence for statechart prefix */
	prefix_enseq_TECX_default(handle);
	prefix_enseq_IDLE_default(handle);
	prefix_enseq_MODO_default(handle);
	prefix_enseq_MICROONDAS_default(handle);
	prefix_enseq_LED2_default(handle);
	prefix_enseq_LED3_default(handle);
}

void prefix_exit(Prefix* handle)
{
	/* Default exit sequence for statechart prefix */
	prefix_exseq_TECX(handle);
	prefix_exseq_IDLE(handle);
	prefix_exseq_MODO(handle);
	prefix_exseq_MICROONDAS(handle);
	prefix_exseq_LED2(handle);
	prefix_exseq_LED3(handle);
}

sc_boolean prefix_isActive(const Prefix* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Prefix_last_state || handle->stateConfVector[1] != Prefix_last_state || handle->stateConfVector[2] != Prefix_last_state || handle->stateConfVector[3] != Prefix_last_state || handle->stateConfVector[4] != Prefix_last_state || handle->stateConfVector[5] != Prefix_last_state)
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
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.siPuertaAbierta_raised = bool_false;
	handle->internal.siCambioModo_raised = bool_false;
	handle->internal.siOnOff_raised = bool_false;
	handle->internal.siTitilaL2UP_raised = bool_false;
	handle->internal.siTitilaEncendido_raised = bool_false;
	handle->internal.siTitilaApagado_raised = bool_false;
	handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.prefix_MICROONDAS_ENCENDIDO_tev0_raised = bool_false;
	handle->timeEvents.prefix_LED2_Titala_UP_tev0_raised = bool_false;
	handle->timeEvents.prefix_LED2_Titala_UP_r1_Apagado_tev0_raised = bool_false;
	handle->timeEvents.prefix_LED2_Titala_UP_r1_Encendido_tev0_raised = bool_false;
	handle->timeEvents.prefix_LED3_Titila_Tension_r1_Apagado_tev0_raised = bool_false;
	handle->timeEvents.prefix_LED3_Titila_Tension_r1_Encendido_tev0_raised = bool_false;
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
		case Prefix_IDLE_ESPERA :
		{
			prefix_react_IDLE_ESPERA(handle);
			break;
		}
		case Prefix_MODO_NORMAL :
		{
			prefix_react_MODO_NORMAL(handle);
			break;
		}
		case Prefix_MODO_GRILL :
		{
			prefix_react_MODO_GRILL(handle);
			break;
		}
		case Prefix_MODO_DESCONGELAR :
		{
			prefix_react_MODO_DESCONGELAR(handle);
			break;
		}
		case Prefix_MICROONDAS_APAGADO :
		{
			prefix_react_MICROONDAS_APAGADO(handle);
			break;
		}
		case Prefix_MICROONDAS_ENCENDIDO :
		{
			prefix_react_MICROONDAS_ENCENDIDO(handle);
			break;
		}
		case Prefix_LED2_Reposo :
		{
			prefix_react_LED2_Reposo(handle);
			break;
		}
		case Prefix_LED2_Titala_UP_r1_Apagado :
		{
			prefix_react_LED2_Titala_UP_r1_Apagado(handle);
			break;
		}
		case Prefix_LED2_Titala_UP_r1_Encendido :
		{
			prefix_react_LED2_Titala_UP_r1_Encendido(handle);
			break;
		}
		case Prefix_LED3_Reposo :
		{
			prefix_react_LED3_Reposo(handle);
			break;
		}
		case Prefix_LED3_Titila_Tension_r1_Apagado :
		{
			prefix_react_LED3_Titila_Tension_r1_Apagado(handle);
			break;
		}
		case Prefix_LED3_Titila_Tension_r1_Encendido :
		{
			prefix_react_LED3_Titila_Tension_r1_Encendido(handle);
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
		case Prefix_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_NO_OPRIMIDO
			);
			break;
		case Prefix_TECX_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_DEBOUNCE
			);
			break;
		case Prefix_TECX_VALIDATION :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_VALIDATION
			);
			break;
		case Prefix_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_OPRIMIDO
			);
			break;
		case Prefix_IDLE_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_IDLE_ESPERA
			);
			break;
		case Prefix_MODO_NORMAL :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_MODO_NORMAL
			);
			break;
		case Prefix_MODO_GRILL :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_MODO_GRILL
			);
			break;
		case Prefix_MODO_DESCONGELAR :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_MODO_DESCONGELAR
			);
			break;
		case Prefix_MICROONDAS_APAGADO :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_MICROONDAS_APAGADO
			);
			break;
		case Prefix_MICROONDAS_ENCENDIDO :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_MICROONDAS_ENCENDIDO
			);
			break;
		case Prefix_LED2_Reposo :
			result = (sc_boolean) (handle->stateConfVector[4] == Prefix_LED2_Reposo
			);
			break;
		case Prefix_LED2_Titala_UP :
			result = (sc_boolean) (handle->stateConfVector[4] >= Prefix_LED2_Titala_UP
				&& handle->stateConfVector[4] <= Prefix_LED2_Titala_UP_r1_Encendido);
			break;
		case Prefix_LED2_Titala_UP_r1_Apagado :
			result = (sc_boolean) (handle->stateConfVector[4] == Prefix_LED2_Titala_UP_r1_Apagado
			);
			break;
		case Prefix_LED2_Titala_UP_r1_Encendido :
			result = (sc_boolean) (handle->stateConfVector[4] == Prefix_LED2_Titala_UP_r1_Encendido
			);
			break;
		case Prefix_LED3_Reposo :
			result = (sc_boolean) (handle->stateConfVector[5] == Prefix_LED3_Reposo
			);
			break;
		case Prefix_LED3_Titila_Tension :
			result = (sc_boolean) (handle->stateConfVector[5] >= Prefix_LED3_Titila_Tension
				&& handle->stateConfVector[5] <= Prefix_LED3_Titila_Tension_r1_Encendido);
			break;
		case Prefix_LED3_Titila_Tension_r1_Apagado :
			result = (sc_boolean) (handle->stateConfVector[5] == Prefix_LED3_Titila_Tension_r1_Apagado
			);
			break;
		case Prefix_LED3_Titila_Tension_r1_Encendido :
			result = (sc_boolean) (handle->stateConfVector[5] == Prefix_LED3_Titila_Tension_r1_Encendido
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


const sc_integer prefixIface_get_lEDR(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDR;
}
const sc_integer prefixIface_get_lEDG(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDG;
}
const sc_integer prefixIface_get_lEDB(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDB;
}
const sc_integer prefixIface_get_lED1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED1;
}
const sc_integer prefixIface_get_lED2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED2;
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

static sc_boolean prefix_check_IDLE_ESPERA_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC1)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr1_tr1(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC2)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_IDLE_ESPERA_tr2_tr2(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC4)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_MODO_NORMAL_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siCambioModo_raised;
}

static sc_boolean prefix_check_MODO_GRILL_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siCambioModo_raised;
}

static sc_boolean prefix_check_MODO_DESCONGELAR_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siCambioModo_raised;
}

static sc_boolean prefix_check_MICROONDAS_APAGADO_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siOnOff_raised;
}

static sc_boolean prefix_check_MICROONDAS_ENCENDIDO_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siOnOff_raised;
}

static sc_boolean prefix_check_MICROONDAS_ENCENDIDO_tr1_tr1(const Prefix* handle)
{
	return handle->internal.siPuertaAbierta_raised;
}

static sc_boolean prefix_check_MICROONDAS_ENCENDIDO_tr2_tr2(const Prefix* handle)
{
	return handle->timeEvents.prefix_MICROONDAS_ENCENDIDO_tev0_raised;
}

static sc_boolean prefix_check_LED2_Reposo_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siTitilaL2UP_raised;
}

static sc_boolean prefix_check_LED2_Titala_UP_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_LED2_Titala_UP_tev0_raised;
}

static sc_boolean prefix_check_LED2_Titala_UP_r1_Apagado_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_LED2_Titala_UP_r1_Apagado_tev0_raised;
}

static sc_boolean prefix_check_LED2_Titala_UP_r1_Encendido_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_LED2_Titala_UP_r1_Encendido_tev0_raised;
}

static sc_boolean prefix_check_LED3_Reposo_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siTitilaEncendido_raised;
}

static sc_boolean prefix_check_LED3_Titila_Tension_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siTitilaApagado_raised;
}

static sc_boolean prefix_check_LED3_Titila_Tension_r1_Apagado_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_LED3_Titila_Tension_r1_Apagado_tev0_raised;
}

static sc_boolean prefix_check_LED3_Titila_Tension_r1_Encendido_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_LED3_Titila_Tension_r1_Encendido_tev0_raised;
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

static void prefix_effect_IDLE_ESPERA_tr0(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siCambioModo_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr1(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siOnOff_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_IDLE_ESPERA_tr2(Prefix* handle)
{
	prefix_exseq_IDLE_ESPERA(handle);
	handle->internal.siPuertaAbierta_raised = bool_true;
	prefix_enseq_IDLE_ESPERA_default(handle);
}

static void prefix_effect_MODO_NORMAL_tr0(Prefix* handle)
{
	prefix_exseq_MODO_NORMAL(handle);
	prefix_enseq_MODO_DESCONGELAR_default(handle);
}

static void prefix_effect_MODO_GRILL_tr0(Prefix* handle)
{
	prefix_exseq_MODO_GRILL(handle);
	prefix_enseq_MODO_NORMAL_default(handle);
}

static void prefix_effect_MODO_DESCONGELAR_tr0(Prefix* handle)
{
	prefix_exseq_MODO_DESCONGELAR(handle);
	prefix_enseq_MODO_GRILL_default(handle);
}

static void prefix_effect_MICROONDAS_APAGADO_tr0(Prefix* handle)
{
	prefix_exseq_MICROONDAS_APAGADO(handle);
	prefix_enseq_MICROONDAS_ENCENDIDO_default(handle);
}

static void prefix_effect_MICROONDAS_ENCENDIDO_tr0(Prefix* handle)
{
	prefix_exseq_MICROONDAS_ENCENDIDO(handle);
	prefix_enseq_MICROONDAS_APAGADO_default(handle);
}

static void prefix_effect_MICROONDAS_ENCENDIDO_tr1(Prefix* handle)
{
	prefix_exseq_MICROONDAS_ENCENDIDO(handle);
	handle->internal.siTitilaL2UP_raised = bool_true;
	prefix_enseq_MICROONDAS_APAGADO_default(handle);
}

static void prefix_effect_MICROONDAS_ENCENDIDO_tr2(Prefix* handle)
{
	prefix_exseq_MICROONDAS_ENCENDIDO(handle);
	prefix_enseq_MICROONDAS_APAGADO_default(handle);
}

static void prefix_effect_LED2_Reposo_tr0(Prefix* handle)
{
	prefix_exseq_LED2_Reposo(handle);
	prefix_enseq_LED2_Titala_UP_default(handle);
}

static void prefix_effect_LED2_Titala_UP_tr0(Prefix* handle)
{
	prefix_exseq_LED2_Titala_UP(handle);
	prefix_enseq_LED2_Reposo_default(handle);
}

static void prefix_effect_LED2_Titala_UP_r1_Apagado_tr0(Prefix* handle)
{
	prefix_exseq_LED2_Titala_UP_r1_Apagado(handle);
	prefix_enseq_LED2_Titala_UP_r1_Encendido_default(handle);
}

static void prefix_effect_LED2_Titala_UP_r1_Encendido_tr0(Prefix* handle)
{
	prefix_exseq_LED2_Titala_UP_r1_Encendido(handle);
	prefix_enseq_LED2_Titala_UP_r1_Apagado_default(handle);
}

static void prefix_effect_LED3_Reposo_tr0(Prefix* handle)
{
	prefix_exseq_LED3_Reposo(handle);
	prefix_enseq_LED3_Titila_Tension_default(handle);
}

static void prefix_effect_LED3_Titila_Tension_tr0(Prefix* handle)
{
	prefix_exseq_LED3_Titila_Tension(handle);
	prefix_enseq_LED3_Reposo_default(handle);
}

static void prefix_effect_LED3_Titila_Tension_r1_Apagado_tr0(Prefix* handle)
{
	prefix_exseq_LED3_Titila_Tension_r1_Apagado(handle);
	prefix_enseq_LED3_Titila_Tension_r1_Encendido_default(handle);
}

static void prefix_effect_LED3_Titila_Tension_r1_Encendido_tr0(Prefix* handle)
{
	prefix_exseq_LED3_Titila_Tension_r1_Encendido(handle);
	prefix_enseq_LED3_Titila_Tension_r1_Apagado_default(handle);
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

/* Entry action for state 'NORMAL'. */
static void prefix_enact_MODO_NORMAL(Prefix* handle)
{
	/* Entry action for state 'NORMAL'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_ON);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'GRILL'. */
static void prefix_enact_MODO_GRILL(Prefix* handle)
{
	/* Entry action for state 'GRILL'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'DESCONGELAR'. */
static void prefix_enact_MODO_DESCONGELAR(Prefix* handle)
{
	/* Entry action for state 'DESCONGELAR'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_ON);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'APAGADO'. */
static void prefix_enact_MICROONDAS_APAGADO(Prefix* handle)
{
	/* Entry action for state 'APAGADO'. */
	handle->internal.siTitilaApagado_raised = bool_true;
}

/* Entry action for state 'ENCENDIDO'. */
static void prefix_enact_MICROONDAS_ENCENDIDO(Prefix* handle)
{
	/* Entry action for state 'ENCENDIDO'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_MICROONDAS_ENCENDIDO_tev0_raised) , 30000, bool_false);
	handle->internal.siTitilaEncendido_raised = bool_true;
}

/* Entry action for state 'Reposo'. */
static void prefix_enact_LED2_Reposo(Prefix* handle)
{
	/* Entry action for state 'Reposo'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED2, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'Titala_UP'. */
static void prefix_enact_LED2_Titala_UP(Prefix* handle)
{
	/* Entry action for state 'Titala_UP'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED2_Titala_UP_tev0_raised) , 750, bool_false);
}

/* Entry action for state 'Apagado'. */
static void prefix_enact_LED2_Titala_UP_r1_Apagado(Prefix* handle)
{
	/* Entry action for state 'Apagado'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED2_Titala_UP_r1_Apagado_tev0_raised) , 50, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED2, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'Encendido'. */
static void prefix_enact_LED2_Titala_UP_r1_Encendido(Prefix* handle)
{
	/* Entry action for state 'Encendido'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED2_Titala_UP_r1_Encendido_tev0_raised) , 100, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED2, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'Reposo'. */
static void prefix_enact_LED3_Reposo(Prefix* handle)
{
	/* Entry action for state 'Reposo'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'Apagado'. */
static void prefix_enact_LED3_Titila_Tension_r1_Apagado(Prefix* handle)
{
	/* Entry action for state 'Apagado'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED3_Titila_Tension_r1_Apagado_tev0_raised) , 250, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'Encendido'. */
static void prefix_enact_LED3_Titila_Tension_r1_Encendido(Prefix* handle)
{
	/* Entry action for state 'Encendido'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED3_Titila_Tension_r1_Encendido_tev0_raised) , 500, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_ON);
}

/* Exit action for state 'DEBOUNCE'. */
static void prefix_exact_TECX_DEBOUNCE(Prefix* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised) );		
}

/* Exit action for state 'ENCENDIDO'. */
static void prefix_exact_MICROONDAS_ENCENDIDO(Prefix* handle)
{
	/* Exit action for state 'ENCENDIDO'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_MICROONDAS_ENCENDIDO_tev0_raised) );		
}

/* Exit action for state 'Titala_UP'. */
static void prefix_exact_LED2_Titala_UP(Prefix* handle)
{
	/* Exit action for state 'Titala_UP'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED2_Titala_UP_tev0_raised) );		
}

/* Exit action for state 'Apagado'. */
static void prefix_exact_LED2_Titala_UP_r1_Apagado(Prefix* handle)
{
	/* Exit action for state 'Apagado'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED2_Titala_UP_r1_Apagado_tev0_raised) );		
}

/* Exit action for state 'Encendido'. */
static void prefix_exact_LED2_Titala_UP_r1_Encendido(Prefix* handle)
{
	/* Exit action for state 'Encendido'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED2_Titala_UP_r1_Encendido_tev0_raised) );		
}

/* Exit action for state 'Apagado'. */
static void prefix_exact_LED3_Titila_Tension_r1_Apagado(Prefix* handle)
{
	/* Exit action for state 'Apagado'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED3_Titila_Tension_r1_Apagado_tev0_raised) );		
}

/* Exit action for state 'Encendido'. */
static void prefix_exact_LED3_Titila_Tension_r1_Encendido(Prefix* handle)
{
	/* Exit action for state 'Encendido'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED3_Titila_Tension_r1_Encendido_tev0_raised) );		
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state DEBOUNCE */
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	prefix_enact_TECX_DEBOUNCE(handle);
	handle->stateConfVector[0] = Prefix_TECX_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDATION */
static void prefix_enseq_TECX_VALIDATION_default(Prefix* handle)
{
	/* 'default' enter sequence for state VALIDATION */
	handle->stateConfVector[0] = Prefix_TECX_VALIDATION;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	prefix_enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[0] = Prefix_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ESPERA */
static void prefix_enseq_IDLE_ESPERA_default(Prefix* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[1] = Prefix_IDLE_ESPERA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state NORMAL */
static void prefix_enseq_MODO_NORMAL_default(Prefix* handle)
{
	/* 'default' enter sequence for state NORMAL */
	prefix_enact_MODO_NORMAL(handle);
	handle->stateConfVector[2] = Prefix_MODO_NORMAL;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state GRILL */
static void prefix_enseq_MODO_GRILL_default(Prefix* handle)
{
	/* 'default' enter sequence for state GRILL */
	prefix_enact_MODO_GRILL(handle);
	handle->stateConfVector[2] = Prefix_MODO_GRILL;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state DESCONGELAR */
static void prefix_enseq_MODO_DESCONGELAR_default(Prefix* handle)
{
	/* 'default' enter sequence for state DESCONGELAR */
	prefix_enact_MODO_DESCONGELAR(handle);
	handle->stateConfVector[2] = Prefix_MODO_DESCONGELAR;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state APAGADO */
static void prefix_enseq_MICROONDAS_APAGADO_default(Prefix* handle)
{
	/* 'default' enter sequence for state APAGADO */
	prefix_enact_MICROONDAS_APAGADO(handle);
	handle->stateConfVector[3] = Prefix_MICROONDAS_APAGADO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state ENCENDIDO */
static void prefix_enseq_MICROONDAS_ENCENDIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state ENCENDIDO */
	prefix_enact_MICROONDAS_ENCENDIDO(handle);
	handle->stateConfVector[3] = Prefix_MICROONDAS_ENCENDIDO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state Reposo */
static void prefix_enseq_LED2_Reposo_default(Prefix* handle)
{
	/* 'default' enter sequence for state Reposo */
	prefix_enact_LED2_Reposo(handle);
	handle->stateConfVector[4] = Prefix_LED2_Reposo;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state Titala_UP */
static void prefix_enseq_LED2_Titala_UP_default(Prefix* handle)
{
	/* 'default' enter sequence for state Titala_UP */
	prefix_enact_LED2_Titala_UP(handle);
	prefix_enseq_LED2_Titala_UP_r1_default(handle);
}

/* 'default' enter sequence for state Apagado */
static void prefix_enseq_LED2_Titala_UP_r1_Apagado_default(Prefix* handle)
{
	/* 'default' enter sequence for state Apagado */
	prefix_enact_LED2_Titala_UP_r1_Apagado(handle);
	handle->stateConfVector[4] = Prefix_LED2_Titala_UP_r1_Apagado;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state Encendido */
static void prefix_enseq_LED2_Titala_UP_r1_Encendido_default(Prefix* handle)
{
	/* 'default' enter sequence for state Encendido */
	prefix_enact_LED2_Titala_UP_r1_Encendido(handle);
	handle->stateConfVector[4] = Prefix_LED2_Titala_UP_r1_Encendido;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state Reposo */
static void prefix_enseq_LED3_Reposo_default(Prefix* handle)
{
	/* 'default' enter sequence for state Reposo */
	prefix_enact_LED3_Reposo(handle);
	handle->stateConfVector[5] = Prefix_LED3_Reposo;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for state Titila_Tension */
static void prefix_enseq_LED3_Titila_Tension_default(Prefix* handle)
{
	/* 'default' enter sequence for state Titila_Tension */
	prefix_enseq_LED3_Titila_Tension_r1_default(handle);
}

/* 'default' enter sequence for state Apagado */
static void prefix_enseq_LED3_Titila_Tension_r1_Apagado_default(Prefix* handle)
{
	/* 'default' enter sequence for state Apagado */
	prefix_enact_LED3_Titila_Tension_r1_Apagado(handle);
	handle->stateConfVector[5] = Prefix_LED3_Titila_Tension_r1_Apagado;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for state Encendido */
static void prefix_enseq_LED3_Titila_Tension_r1_Encendido_default(Prefix* handle)
{
	/* 'default' enter sequence for state Encendido */
	prefix_enact_LED3_Titila_Tension_r1_Encendido(handle);
	handle->stateConfVector[5] = Prefix_LED3_Titila_Tension_r1_Encendido;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for region TECX */
static void prefix_enseq_TECX_default(Prefix* handle)
{
	/* 'default' enter sequence for region TECX */
	prefix_react_TECX__entry_Default(handle);
}

/* 'default' enter sequence for region IDLE */
static void prefix_enseq_IDLE_default(Prefix* handle)
{
	/* 'default' enter sequence for region IDLE */
	prefix_react_IDLE__entry_Default(handle);
}

/* 'default' enter sequence for region MODO */
static void prefix_enseq_MODO_default(Prefix* handle)
{
	/* 'default' enter sequence for region MODO */
	prefix_react_MODO__entry_Default(handle);
}

/* 'default' enter sequence for region MICROONDAS */
static void prefix_enseq_MICROONDAS_default(Prefix* handle)
{
	/* 'default' enter sequence for region MICROONDAS */
	prefix_react_MICROONDAS__entry_Default(handle);
}

/* 'default' enter sequence for region LED2 */
static void prefix_enseq_LED2_default(Prefix* handle)
{
	/* 'default' enter sequence for region LED2 */
	prefix_react_LED2__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void prefix_enseq_LED2_Titala_UP_r1_default(Prefix* handle)
{
	/* 'default' enter sequence for region r1 */
	prefix_react_LED2_Titala_UP_r1__entry_Default(handle);
}

/* 'default' enter sequence for region LED3 */
static void prefix_enseq_LED3_default(Prefix* handle)
{
	/* 'default' enter sequence for region LED3 */
	prefix_react_LED3__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void prefix_enseq_LED3_Titila_Tension_r1_default(Prefix* handle)
{
	/* 'default' enter sequence for region r1 */
	prefix_react_LED3_Titila_Tension_r1__entry_Default(handle);
}

/* Default exit sequence for state NO_OPRIMIDO */
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state DEBOUNCE */
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
	prefix_exact_TECX_DEBOUNCE(handle);
}

/* Default exit sequence for state VALIDATION */
static void prefix_exseq_TECX_VALIDATION(Prefix* handle)
{
	/* Default exit sequence for state VALIDATION */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ESPERA */
static void prefix_exseq_IDLE_ESPERA(Prefix* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state NORMAL */
static void prefix_exseq_MODO_NORMAL(Prefix* handle)
{
	/* Default exit sequence for state NORMAL */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state GRILL */
static void prefix_exseq_MODO_GRILL(Prefix* handle)
{
	/* Default exit sequence for state GRILL */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state DESCONGELAR */
static void prefix_exseq_MODO_DESCONGELAR(Prefix* handle)
{
	/* Default exit sequence for state DESCONGELAR */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state APAGADO */
static void prefix_exseq_MICROONDAS_APAGADO(Prefix* handle)
{
	/* Default exit sequence for state APAGADO */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state ENCENDIDO */
static void prefix_exseq_MICROONDAS_ENCENDIDO(Prefix* handle)
{
	/* Default exit sequence for state ENCENDIDO */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
	prefix_exact_MICROONDAS_ENCENDIDO(handle);
}

/* Default exit sequence for state Reposo */
static void prefix_exseq_LED2_Reposo(Prefix* handle)
{
	/* Default exit sequence for state Reposo */
	handle->stateConfVector[4] = Prefix_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state Titala_UP */
static void prefix_exseq_LED2_Titala_UP(Prefix* handle)
{
	/* Default exit sequence for state Titala_UP */
	prefix_exseq_LED2_Titala_UP_r1(handle);
	prefix_exact_LED2_Titala_UP(handle);
}

/* Default exit sequence for state Apagado */
static void prefix_exseq_LED2_Titala_UP_r1_Apagado(Prefix* handle)
{
	/* Default exit sequence for state Apagado */
	handle->stateConfVector[4] = Prefix_last_state;
	handle->stateConfVectorPosition = 4;
	prefix_exact_LED2_Titala_UP_r1_Apagado(handle);
}

/* Default exit sequence for state Encendido */
static void prefix_exseq_LED2_Titala_UP_r1_Encendido(Prefix* handle)
{
	/* Default exit sequence for state Encendido */
	handle->stateConfVector[4] = Prefix_last_state;
	handle->stateConfVectorPosition = 4;
	prefix_exact_LED2_Titala_UP_r1_Encendido(handle);
}

/* Default exit sequence for state Reposo */
static void prefix_exseq_LED3_Reposo(Prefix* handle)
{
	/* Default exit sequence for state Reposo */
	handle->stateConfVector[5] = Prefix_last_state;
	handle->stateConfVectorPosition = 5;
}

/* Default exit sequence for state Titila_Tension */
static void prefix_exseq_LED3_Titila_Tension(Prefix* handle)
{
	/* Default exit sequence for state Titila_Tension */
	prefix_exseq_LED3_Titila_Tension_r1(handle);
}

/* Default exit sequence for state Apagado */
static void prefix_exseq_LED3_Titila_Tension_r1_Apagado(Prefix* handle)
{
	/* Default exit sequence for state Apagado */
	handle->stateConfVector[5] = Prefix_last_state;
	handle->stateConfVectorPosition = 5;
	prefix_exact_LED3_Titila_Tension_r1_Apagado(handle);
}

/* Default exit sequence for state Encendido */
static void prefix_exseq_LED3_Titila_Tension_r1_Encendido(Prefix* handle)
{
	/* Default exit sequence for state Encendido */
	handle->stateConfVector[5] = Prefix_last_state;
	handle->stateConfVectorPosition = 5;
	prefix_exact_LED3_Titila_Tension_r1_Encendido(handle);
}

/* Default exit sequence for region TECX */
static void prefix_exseq_TECX(Prefix* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of prefix.TECX) at position 0... */
	switch(handle->stateConfVector[ 0 ])
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

/* Default exit sequence for region MODO */
static void prefix_exseq_MODO(Prefix* handle)
{
	/* Default exit sequence for region MODO */
	/* Handle exit of all possible states (of prefix.MODO) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_MODO_NORMAL :
		{
			prefix_exseq_MODO_NORMAL(handle);
			break;
		}
		case Prefix_MODO_GRILL :
		{
			prefix_exseq_MODO_GRILL(handle);
			break;
		}
		case Prefix_MODO_DESCONGELAR :
		{
			prefix_exseq_MODO_DESCONGELAR(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region MICROONDAS */
static void prefix_exseq_MICROONDAS(Prefix* handle)
{
	/* Default exit sequence for region MICROONDAS */
	/* Handle exit of all possible states (of prefix.MICROONDAS) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Prefix_MICROONDAS_APAGADO :
		{
			prefix_exseq_MICROONDAS_APAGADO(handle);
			break;
		}
		case Prefix_MICROONDAS_ENCENDIDO :
		{
			prefix_exseq_MICROONDAS_ENCENDIDO(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region LED2 */
static void prefix_exseq_LED2(Prefix* handle)
{
	/* Default exit sequence for region LED2 */
	/* Handle exit of all possible states (of prefix.LED2) at position 4... */
	switch(handle->stateConfVector[ 4 ])
	{
		case Prefix_LED2_Reposo :
		{
			prefix_exseq_LED2_Reposo(handle);
			break;
		}
		case Prefix_LED2_Titala_UP_r1_Apagado :
		{
			prefix_exseq_LED2_Titala_UP_r1_Apagado(handle);
			prefix_exact_LED2_Titala_UP(handle);
			break;
		}
		case Prefix_LED2_Titala_UP_r1_Encendido :
		{
			prefix_exseq_LED2_Titala_UP_r1_Encendido(handle);
			prefix_exact_LED2_Titala_UP(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void prefix_exseq_LED2_Titala_UP_r1(Prefix* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of prefix.LED2.Titala_UP.r1) at position 4... */
	switch(handle->stateConfVector[ 4 ])
	{
		case Prefix_LED2_Titala_UP_r1_Apagado :
		{
			prefix_exseq_LED2_Titala_UP_r1_Apagado(handle);
			break;
		}
		case Prefix_LED2_Titala_UP_r1_Encendido :
		{
			prefix_exseq_LED2_Titala_UP_r1_Encendido(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region LED3 */
static void prefix_exseq_LED3(Prefix* handle)
{
	/* Default exit sequence for region LED3 */
	/* Handle exit of all possible states (of prefix.LED3) at position 5... */
	switch(handle->stateConfVector[ 5 ])
	{
		case Prefix_LED3_Reposo :
		{
			prefix_exseq_LED3_Reposo(handle);
			break;
		}
		case Prefix_LED3_Titila_Tension_r1_Apagado :
		{
			prefix_exseq_LED3_Titila_Tension_r1_Apagado(handle);
			break;
		}
		case Prefix_LED3_Titila_Tension_r1_Encendido :
		{
			prefix_exseq_LED3_Titila_Tension_r1_Encendido(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void prefix_exseq_LED3_Titila_Tension_r1(Prefix* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of prefix.LED3.Titila_Tension.r1) at position 5... */
	switch(handle->stateConfVector[ 5 ])
	{
		case Prefix_LED3_Titila_Tension_r1_Apagado :
		{
			prefix_exseq_LED3_Titila_Tension_r1_Apagado(handle);
			break;
		}
		case Prefix_LED3_Titila_Tension_r1_Encendido :
		{
			prefix_exseq_LED3_Titila_Tension_r1_Encendido(handle);
			break;
		}
		default: break;
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
		}  else
		{
			if (prefix_check_IDLE_ESPERA_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_IDLE_ESPERA_tr2(handle);
			} 
		}
	}
}

/* The reactions of state NORMAL. */
static void prefix_react_MODO_NORMAL(Prefix* handle)
{
	/* The reactions of state NORMAL. */
	if (prefix_check_MODO_NORMAL_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_MODO_NORMAL_tr0(handle);
	} 
}

/* The reactions of state GRILL. */
static void prefix_react_MODO_GRILL(Prefix* handle)
{
	/* The reactions of state GRILL. */
	if (prefix_check_MODO_GRILL_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_MODO_GRILL_tr0(handle);
	} 
}

/* The reactions of state DESCONGELAR. */
static void prefix_react_MODO_DESCONGELAR(Prefix* handle)
{
	/* The reactions of state DESCONGELAR. */
	if (prefix_check_MODO_DESCONGELAR_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_MODO_DESCONGELAR_tr0(handle);
	} 
}

/* The reactions of state APAGADO. */
static void prefix_react_MICROONDAS_APAGADO(Prefix* handle)
{
	/* The reactions of state APAGADO. */
	if (prefix_check_MICROONDAS_APAGADO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_MICROONDAS_APAGADO_tr0(handle);
	} 
}

/* The reactions of state ENCENDIDO. */
static void prefix_react_MICROONDAS_ENCENDIDO(Prefix* handle)
{
	/* The reactions of state ENCENDIDO. */
	if (prefix_check_MICROONDAS_ENCENDIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_MICROONDAS_ENCENDIDO_tr0(handle);
	}  else
	{
		if (prefix_check_MICROONDAS_ENCENDIDO_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_MICROONDAS_ENCENDIDO_tr1(handle);
		}  else
		{
			if (prefix_check_MICROONDAS_ENCENDIDO_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_MICROONDAS_ENCENDIDO_tr2(handle);
			} 
		}
	}
}

/* The reactions of state Reposo. */
static void prefix_react_LED2_Reposo(Prefix* handle)
{
	/* The reactions of state Reposo. */
	if (prefix_check_LED2_Reposo_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED2_Reposo_tr0(handle);
	} 
}

/* The reactions of state Apagado. */
static void prefix_react_LED2_Titala_UP_r1_Apagado(Prefix* handle)
{
	/* The reactions of state Apagado. */
	if (prefix_check_LED2_Titala_UP_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED2_Titala_UP_tr0(handle);
	}  else
	{
		if (prefix_check_LED2_Titala_UP_r1_Apagado_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_LED2_Titala_UP_r1_Apagado_tr0(handle);
		} 
	}
}

/* The reactions of state Encendido. */
static void prefix_react_LED2_Titala_UP_r1_Encendido(Prefix* handle)
{
	/* The reactions of state Encendido. */
	if (prefix_check_LED2_Titala_UP_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED2_Titala_UP_tr0(handle);
	}  else
	{
		if (prefix_check_LED2_Titala_UP_r1_Encendido_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_LED2_Titala_UP_r1_Encendido_tr0(handle);
		} 
	}
}

/* The reactions of state Reposo. */
static void prefix_react_LED3_Reposo(Prefix* handle)
{
	/* The reactions of state Reposo. */
	if (prefix_check_LED3_Reposo_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED3_Reposo_tr0(handle);
	} 
}

/* The reactions of state Apagado. */
static void prefix_react_LED3_Titila_Tension_r1_Apagado(Prefix* handle)
{
	/* The reactions of state Apagado. */
	if (prefix_check_LED3_Titila_Tension_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED3_Titila_Tension_tr0(handle);
	}  else
	{
		if (prefix_check_LED3_Titila_Tension_r1_Apagado_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_LED3_Titila_Tension_r1_Apagado_tr0(handle);
		} 
	}
}

/* The reactions of state Encendido. */
static void prefix_react_LED3_Titila_Tension_r1_Encendido(Prefix* handle)
{
	/* The reactions of state Encendido. */
	if (prefix_check_LED3_Titila_Tension_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED3_Titila_Tension_tr0(handle);
	}  else
	{
		if (prefix_check_LED3_Titila_Tension_r1_Encendido_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_LED3_Titila_Tension_r1_Encendido_tr0(handle);
		} 
	}
}

/* Default react sequence for initial entry  */
static void prefix_react_TECX__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_IDLE__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_IDLE_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_MODO__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_MODO_NORMAL_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_MICROONDAS__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_MICROONDAS_APAGADO_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LED2__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LED2_Reposo_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LED2_Titala_UP_r1__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LED2_Titala_UP_r1_Apagado_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LED3__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LED3_Reposo_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LED3_Titila_Tension_r1__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LED3_Titila_Tension_r1_Apagado_default(handle);
}


