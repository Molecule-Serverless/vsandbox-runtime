/*
 * librunf - vectorized sandbox runtime for FPGA
 *
 * Copyright (C) 2021 Dong Du <Dd_nirvana@sjtu.edu.cn>
 * librunf is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * librunf is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with librunf.  If not, see <http://www.gnu.org/licenses/>.
 */
#define _GNU_SOURCE

#include <stdlib.h>
#include "../libcrun/container.h"
#include <stdio.h>
#include <string.h>

#define PATH "/home/centos/src/project_data/aws-fpga/Vitis/helloworld_genbin/"
#define INVOKER "func_invoker"
#define FUNC_NAME "fpga_func.awsxclbin"

int
librunf_vsandbox_run (libcrun_container_t *container, unsigned int options)
{
	/* TODO(DD): We should check the length to avoid too long args */
	char cmd[256];
	char** vargs = container->container_def->process->vargs;
	int vargs_len = container->container_def->process->vargs_len;
	int i;

#if 0 /* Debug code, printing all sandboxes */
	for (i=0; i<container->container_def->process->vargs_len; i++) {
		fprintf(stderr, "[VSandbox] sandbox-%d: %s\n", i,
				container->container_def->process->vargs[i]);
	}
#endif

	if (vargs == NULL || vargs_len ==0) {
		strcpy (cmd, PATH INVOKER " " PATH FUNC_NAME "\0");
		system(cmd);
	} else {
		for (i=0; i<vargs_len; i++){
			strcpy(cmd, vargs[i]);
			strcat (cmd, "\0");
			system(cmd);
		}
	}

	return 0;
}
