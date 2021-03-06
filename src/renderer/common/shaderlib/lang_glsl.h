/*
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2019, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2019, Andrei Alexeyev <akari@taisei-project.org>.
 */

#ifndef IGUARD_renderer_common_shaderlib_lang_glsl_h
#define IGUARD_renderer_common_shaderlib_lang_glsl_h

#include "taisei.h"

#include "defs.h"

typedef enum GLSLProfile {
	GLSL_PROFILE_NONE,
	GLSL_PROFILE_CORE,
	GLSL_PROFILE_COMPATIBILITY,
	GLSL_PROFILE_ES,
} GLSLProfile;

typedef struct GLSLVersion {
	uint version;
	GLSLProfile profile;
} GLSLVersion;

typedef struct GLSLMacro {
	const char *name;
	const char *value;
} GLSLMacro;

typedef struct GLSLSourceOptions {
	GLSLVersion version;
	ShaderStage stage;
	bool force_version;
	GLSLMacro *macros;
} GLSLSourceOptions;

bool glsl_load_source(const char *path, ShaderSource *out, const GLSLSourceOptions *options) attr_nonnull(1, 2, 3);
char* glsl_parse_version(const char *str, GLSLVersion *out_version);
int glsl_format_version(char *buf, size_t bufsize, GLSLVersion version);

#endif // IGUARD_renderer_common_shaderlib_lang_glsl_h
