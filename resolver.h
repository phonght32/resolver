// MIT License

// Copyright (c) 2023 phonght32

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __RESOLVER_H__
#define __RESOLVER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "err_code.h"

typedef err_code_t (*resolver_func_start)(void);
typedef err_code_t (*resolver_func_stop)(void);
typedef err_code_t (*resolver_func_set_counter)(uint32_t value);
typedef err_code_t (*resolver_func_get_counter)(uint32_t *value);
typedef err_code_t (*resolver_func_set_mode_up)(void);
typedef err_code_t (*resolver_func_set_mode_down)(void);

typedef struct resolver *resolver_handle_t;

typedef struct {
	uint32_t 					max_reload;             /*!< Max reload value */
	resolver_func_start 		start;					/*!< Function start resolver */
	resolver_func_stop 			stop;					/*!< Function stop resolver */
	resolver_func_set_counter 	set_counter;			/*!< Function set counter */
	resolver_func_get_counter 	get_counter;			/*!< Function get counter */
	resolver_func_set_mode_up	set_mode_up;			/*!< Function set mode counter up */
	resolver_func_set_mode_down set_mode_down;			/*!< Function set mode counter down */
} resolver_cfg_t;

/*
 * @brief   Initialize resolver with default parameters.
 *
 * @note    This function must be called first.
 *
 * @param   None.
 *
 * @return
 *      - Handle structure: Success.
 *      - Others:           Fail.
 */
resolver_handle_t resolver_init(void);

/*
 * @brief   Set configuration parameters.
 *
 * @param 	handle Handle structure.
 * @param   cfg Configuration structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t resolver_set_config(resolver_handle_t handle, resolver_cfg_t cfg);

/*
 * @brief   Configure resolver to run.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t resolver_config(resolver_handle_t handle);

/*
 * @brief   Start resolver.
 *
 * @param   handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t resolver_start(resolver_handle_t handle);

/*
 * @brief   Stop resolver.
 *
 * @param   handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t resolver_stop(resolver_handle_t handle);

/*
 * @brief   Get resolver counter value.
 *
 * @param   handle Handle structure.
 * @param   value Counter value.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t resolver_get_value(resolver_handle_t handle, uint32_t *value);

/*
 * @brief   Set resolver counter value.
 *
 * @param   handle Handle structure.
 * @param   value Counter value.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t resolver_set_value(resolver_handle_t handle, uint32_t value);

/*
 * @brief   Set mode counter up.
 *
 * @param   handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t resolver_set_mode_up(resolver_handle_t handle);

/*
 * @brief   Set mode counter down.
 *
 * @param   handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t resolver_set_mode_down(resolver_handle_t handle);


#ifdef __cplusplus
}
#endif

#endif /* __RESOLVER_H__ */