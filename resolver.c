#include "stdlib.h"
#include "resolver.h"

typedef struct resolver {
	uint32_t 					max_reload;				/*!< Max reload value */
	uint8_t  					is_run; 				/*!< Running status */
	resolver_func_start 		start;					/*!< Function start resolver */
	resolver_func_stop 			stop;					/*!< Function stop resolver */
	resolver_func_set_counter 	set_counter;			/*!< Function set counter */
	resolver_func_get_counter 	get_counter;			/*!< Function get counter */
	resolver_func_set_mode_up	set_mode_up;			/*!< Function set mode counter up */
	resolver_func_set_mode_down set_mode_down;			/*!< Function set mode counter down */
} resolver_t;

resolver_handle_t resolver_init(void)
{
	resolver_handle_t handle = calloc(1, sizeof(resolver_t));
	if (handle == NULL)
	{
		return NULL;
	}

	return handle;
}

err_code_t resolver_set_config(resolver_handle_t handle, resolver_cfg_t cfg)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	handle->max_reload = cfg.max_reload;
	handle->is_run = 0;
	handle->start = cfg.start;
	handle->stop = cfg.stop;
	handle->set_counter = cfg.set_counter;
	handle->get_counter = cfg.get_counter;
	handle->set_mode_up = cfg.set_mode_up;
	handle->set_mode_down = cfg.set_mode_down;

	return ERR_CODE_SUCCESS;
}

err_code_t resolver_config(resolver_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	/* Nothing to do */

	return ERR_CODE_SUCCESS;
}

err_code_t resolver_start(resolver_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->start();
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	handle->is_run = 1;

	return ERR_CODE_SUCCESS;
}

err_code_t resolver_stop(resolver_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->stop();
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	handle->is_run = 0;

	return ERR_CODE_SUCCESS;
}

err_code_t resolver_get_value(resolver_handle_t handle, uint32_t *value)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->get_counter(value);
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	return ERR_CODE_SUCCESS;
}

err_code_t resolver_set_value(resolver_handle_t handle, uint32_t value)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->set_counter(value);
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	return ERR_CODE_SUCCESS;
}

err_code_t resolver_set_mode_up(resolver_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->set_mode_up();
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	return ERR_CODE_SUCCESS;
}

err_code_t resolver_set_mode_down(resolver_handle_t handle)
{
	/* Check if handle structure is NULL */
	if (handle == NULL)
	{
		return ERR_CODE_NULL_PTR;
	}

	err_code_t err;

	err = handle->set_mode_down();
	if (err != ERR_CODE_SUCCESS)
	{
		return err;
	}

	return ERR_CODE_SUCCESS;
}