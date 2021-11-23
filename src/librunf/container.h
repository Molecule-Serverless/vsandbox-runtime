/*
 * crun - OCI runtime written in C
 *
 * Copyright (C) 2017, 2018, 2019 Giuseppe Scrivano <giuseppe@scrivano.org>
 * crun is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * crun is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with crun.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RUNF_CONTAINER_H
#define RUNF_CONTAINER_H

#include "../libcrun/container.h"

LIBCRUN_PUBLIC int librunf_vsandbox_run (libcrun_container_t *container, unsigned int options);

#if 0
LIBCRUN_PUBLIC int libcrun_container_delete (libcrun_context_t *context, runtime_spec_schema_config_schema *def,
                                             const char *id, bool force, libcrun_error_t *err);

LIBCRUN_PUBLIC int libcrun_container_kill (libcrun_context_t *context, const char *id, int signal,
                                           libcrun_error_t *err);

LIBCRUN_PUBLIC int libcrun_container_create (libcrun_context_t *context, libcrun_container_t *container,
                                             unsigned int options, libcrun_error_t *err);

LIBCRUN_PUBLIC int libcrun_container_start (libcrun_context_t *context, const char *id, libcrun_error_t *err);

LIBCRUN_PUBLIC int libcrun_container_state (libcrun_context_t *context, const char *id, FILE *out,
                                            libcrun_error_t *err);
#endif

#endif
