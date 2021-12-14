#include "modelRenderer.hpp"

void ModelRenderer::renderModel(Model *model)
{
	model->getVao()->bind();

	glEnableVertexAttribArray(0);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);

	model->getVao()->unbind();
}
