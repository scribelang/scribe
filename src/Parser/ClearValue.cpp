/*
	MIT License

	Copyright (c) 2021 Scribe Language Repositories

	Permission is hereby granted, free of charge, to any person obtaining a
	copy of this software and associated documentation files (the "Software"), to
	deal in the Software without restriction, including without limitation the
	rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
	sell copies of the Software, and to permit persons to whom the Software is
	furnished to do so.
*/

#include "Parser/Stmts.hpp"

namespace sc
{
///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtBlock ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtBlock::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	for(auto &stmt : stmts) {
		stmt->clearValue();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtType /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtType::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	expr->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// StmtSimple /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtSimple::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////// StmtFnCallInfo ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtFnCallInfo::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	for(auto &a : args) {
		a->clearValue();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtExpr /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtExpr::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	lhs->clearValue();
	if(rhs) rhs->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtVar //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtVar::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	if(vtype) vtype->clearValue();
	if(vval) vval->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtFnSig ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtFnSig::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	for(auto &a : args) a->clearValue();
	if(rettype) rettype->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtFnDef ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtFnDef::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	sig->clearValue();
	if(blk) blk->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// StmtHeader /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtHeader::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtLib //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtLib::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// StmtExtern /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtExtern::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	if(headers) headers->clearValue();
	if(libs) libs->clearValue();
	entity->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////// StmtEnum //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtEnum::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// StmtStruct //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtStruct::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	for(auto &f : fields) f->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////// StmtVarDecl /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtVarDecl::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	for(auto &d : decls) d->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtCond /////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtCond::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	for(auto &c : conds) {
		if(c.getCond()) c.getCond()->clearValue();
		if(c.getBlk()) c.getBlk()->clearValue();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// StmtForIn //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtForIn::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	in->clearValue();
	if(blk) blk->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtFor //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtFor::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	if(init) init->clearValue();
	if(cond) cond->clearValue();
	if(incr) incr->clearValue();
	if(blk) blk->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtWhile ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtWhile::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	if(cond) cond->clearValue();
	if(blk) blk->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtRet //////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtRet::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	if(val) val->clearValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// StmtContinue ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtContinue::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtBreak ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtBreak::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// StmtDefer ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void StmtDefer::clearValue()
{
	if(values[valueid]) values[valueid]->clearHasData();
	if(val) val->clearValue();
}

} // namespace sc