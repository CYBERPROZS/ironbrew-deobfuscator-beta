#pragma once

#include "ast/ir/node.hpp"

// this is the base class that allows to create more compiler passes
namespace deobf::optimization_passes {
	struct base_optimizer {
		//static void run();
		virtual void optimize() = 0;
		virtual ~base_optimizer() noexcept = default;

		explicit base_optimizer(ast::ir::node* root) :
			root(root)
		{ }
	protected:
		ast::ir::node* root = nullptr;
	};
}