/*
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2019, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2019, Andrei Alexeyev <akari@taisei-project.org>.
 * Copyright (c) 2019, p-sam <p-sam@d3vs.net>.
 */

#include "setup.h"

#include "memory/scratch.h"
#include "util/strbuf.h"

static void vfs_setup_onsync(CallChainResult ccr) {
	const char *program_dir = nxGetProgramDir();
	StringBuffer res_path_buf = { acquire_scratch_arena() };
	StringBuffer storage_path_buf = { acquire_scratch_arena() };
	StringBuffer cache_path_buf = { acquire_scratch_arena() };

	strbuf_printf(&res_path_buf, "%s/%s", program_dir, TAISEI_BUILDCONF_DATA_PATH);
	strbuf_printf(&storage_path_buf, "%s/storage", program_dir);
	strbuf_printf(&cache_path_buf, "%s/cache", program_dir);

	VfsSetupFixedPaths paths = {
		.res_path = strbuf_commit(&res_path_buf),
		.storage_path = strbuf_commit(&storage_path_buf),
		.cache_path = strbuf_commit(&cache_path_buf),
	};

	vfs_setup_fixedpaths(&paths);

	release_scratch_arena(res_path_buf.arena);
	release_scratch_arena(storage_path_buf.arena);
	release_scratch_arena(cache_path_buf.arena);

	vfs_setup_onsync_done(ccr);
}

VFS_SETUP_SYNCING(vfs_setup_onsync)
