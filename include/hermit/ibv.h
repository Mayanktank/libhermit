/*
 * Copyright (c) 2017, Annika Wierichs, RWTH Aachen University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the University nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @author Annika Wierichs
 * @file include/hermit/ibv.h
 * @brief TODO
 */

#ifndef __IBV_H__
#define __IBV_H__

#include <hermit/verbs.h>

#ifdef __cplusplus
extern "C" {
#endif


// struct ibv_device **      ibv_get_device_list(int * num_devices);
// const char *              ibv_get_device_name(struct ibv_device *device);
// struct ibv_context *      ibv_open_device(struct ibv_device * device);
// int												ibv_query_port(struct ibv_context * context, uint8_t port_num, struct ibv_port_attr * port_attr);
// struct ibv_comp_channel * ibv_create_comp_channel(struct ibv_context * context);

const char * ibv_wc_status_str(enum ibv_wc_status status);
int ibv_rate_to_mult(enum ibv_rate rate);
enum ibv_rate mult_to_ibv_rate(int mult);
int ibv_rate_to_mbps(enum ibv_rate rate);
enum ibv_rate mbps_to_ibv_rate(int mbps);
struct verbs_context * verbs_get_ctx(struct ibv_context * ctx);
struct ibv_device ** ibv_get_device_list(int * num_devices);
void ibv_free_device_list(struct ibv_device ** list);
const char * ibv_get_device_name(struct ibv_device * device);
__be64 ibv_get_device_guid(struct ibv_device * device);
struct ibv_context * ibv_open_device(struct ibv_device * device);
int ibv_close_device(struct ibv_context * context);
int ibv_get_async_event(struct ibv_context * context, struct ibv_async_event * event);
void ibv_ack_async_event(struct ibv_async_event * event);
int ibv_query_device(struct ibv_context * context, struct ibv_device_attr * device_attr);
int ibv_query_port(struct ibv_context * context, uint8_t port_num, struct ibv_port_attr * port_attr);
int ___ibv_query_port(struct ibv_context * context, uint8_t port_num, struct ibv_port_attr * port_attr);
int ibv_query_gid(struct ibv_context * context, uint8_t port_num, int index, union ibv_gid * gid);
int ibv_query_pkey(struct ibv_context * context, uint8_t port_num, int index, __be16 * pkey);
struct ibv_pd * ibv_alloc_pd(struct ibv_context * context);
int ibv_dealloc_pd(struct ibv_pd * pd);
struct ibv_flow * ibv_create_flow(struct ibv_qp * qp, struct ibv_flow_attr * flow);
int ibv_destroy_flow(struct ibv_flow * flow_id);
struct ibv_xrcd * ibv_open_xrcd(struct ibv_context * context, struct ibv_xrcd_init_attr * xrcd_init_attr);
int ibv_close_xrcd(struct ibv_xrcd * xrcd);
struct ibv_mr * ibv_reg_mr(struct ibv_pd * pd, void * addr, int length, int access);
int ibv_rereg_mr(struct ibv_mr * mr, int flags, struct ibv_pd * pd, void * addr, int length, int access);
int ibv_dereg_mr(struct ibv_mr * mr);
struct ibv_mw * ibv_alloc_mw(struct ibv_pd * pd, enum ibv_mw_type type);
int ibv_dealloc_mw(struct ibv_mw * mw);
uint32_t ibv_inc_rkey(uint32_t rkey);
int ibv_bind_mw(struct ibv_qp * qp, struct ibv_mw * mw, struct ibv_mw_bind * mw_bind);
struct ibv_comp_channel * ibv_create_comp_channel(struct ibv_context * context);
int ibv_destroy_comp_channel(struct ibv_comp_channel * channel);
struct ibv_cq * ibv_create_cq(struct ibv_context * context, int cqe, void * cq_context, struct ibv_comp_channel * channel, int comp_vector);
int ibv_resize_cq(struct ibv_cq * cq, int cqe);
int ibv_destroy_cq(struct ibv_cq * cq);
int ibv_get_cq_event(struct ibv_comp_channel * channel, struct ibv_cq ** cq, void ** cq_context);
void ibv_ack_cq_events(struct ibv_cq * cq, unsigned int nevents);
int ibv_poll_cq(struct ibv_cq * cq, int num_entries, struct ibv_wc * wc);
int ibv_req_notify_cq(struct ibv_cq * cq, int solicited_only);
struct ibv_srq * ibv_create_srq(struct ibv_pd * pd, struct ibv_srq_init_attr * srq_init_attr);
struct ibv_srq * ibv_create_srq_ex(struct ibv_context * context, struct ibv_srq_init_attr_ex * srq_init_attr_ex);
int ibv_modify_srq(struct ibv_srq * srq, struct ibv_srq_attr * srq_attr, int srq_attr_mask);
int ibv_query_srq(struct ibv_srq * srq, struct ibv_srq_attr * srq_attr);
int ibv_get_srq_num(struct ibv_srq * srq, uint32_t * srq_num);
int ibv_destroy_srq(struct ibv_srq * srq);
int ibv_post_srq_recv(struct ibv_srq * srq, struct ibv_recv_wr * recv_wr, struct ibv_recv_wr ** bad_recv_wr);
struct ibv_qp * ibv_create_qp(struct ibv_pd * pd, struct ibv_qp_init_attr * qp_init_attr);
struct ibv_qp * ibv_create_qp_ex(struct ibv_context * context, struct ibv_qp_init_attr_ex * qp_init_attr_ex);
int ibv_query_device_ex(struct ibv_context * context, const struct ibv_query_device_ex_input * input, struct ibv_device_attr_ex * attr);
struct ibv_qp * ibv_open_qp(struct ibv_context * context, struct ibv_qp_open_attr * qp_open_attr);
int ibv_modify_qp(struct ibv_qp * qp, struct ibv_qp_attr * attr, int attr_mask);
int ibv_query_qp(struct ibv_qp * qp, struct ibv_qp_attr * attr, int attr_mask, struct ibv_qp_init_attr * init_attr);
int ibv_destroy_qp(struct ibv_qp * qp);
int ibv_post_send(struct ibv_qp * qp, struct ibv_send_wr * wr, struct ibv_send_wr ** bad_wr);
int ibv_post_recv(struct ibv_qp * qp, struct ibv_recv_wr * wr, struct ibv_recv_wr ** bad_wr);
struct ibv_ah * ibv_create_ah(struct ibv_pd * pd, struct ibv_ah_attr * attr);
int ibv_init_ah_from_wc(struct ibv_context * context, uint8_t port_num, struct ibv_wc * wc, struct ibv_grh * grh, struct ibv_ah_attr * ah_attr);
struct ibv_ah * ibv_create_ah_from_wc(struct ibv_pd * pd, struct ibv_wc * wc, struct ibv_grh * grh, uint8_t port_num);
int ibv_destroy_ah(struct ibv_ah * ah);
int ibv_attach_mcast(struct ibv_qp * qp, const union ibv_gid * gid, uint16_t lid);
int ibv_detach_mcast(struct ibv_qp * qp, const union ibv_gid * gid, uint16_t lid);
int ibv_fork_init( );
const char * ibv_node_type_str(enum ibv_node_type node_type);
const char * ibv_port_state_str(enum ibv_port_state port_state);
const char * ibv_event_type_str(enum ibv_event_type event);
int ibv_is_qpt_supported(uint32_t caps, enum ibv_qp_type qpt);
uint32_t ibv_get_mr_lkey(struct ibv_mr * mr);
uint32_t ibv_get_qp_num(struct ibv_qp * qp);

struct ibv_cq * ibv_cq_ex_to_cq(struct ibv_cq_ex * cq);
int ibv_start_poll(struct ibv_cq_ex * cq, struct ibv_poll_cq_attr * attr);
int ibv_next_poll(struct ibv_cq_ex * cq);
void ibv_end_poll(struct ibv_cq_ex * cq);
uint64_t ibv_wc_read_completion_ts(struct ibv_cq_ex * cq);
struct ibv_cq_ex * ibv_create_cq_ex(struct ibv_context * context, struct ibv_cq_init_attr_ex * cq_attr);

// void kernel_ibv_log();


#ifdef __cplusplus
}
#endif

#endif /* __IBV_H__ */
