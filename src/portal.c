#include "g_local.h"

void func_portal_use()
{				// change to alternate textures
	self->s.v.frame = 1 - self->s.v.frame;
    //dprint("portal use!");

}

void SP_func_portal()
{
	SetVector( self->s.v.angles, 0, 0, 0 );
	self->s.v.movetype = MOVETYPE_NONE;	// so it doesn't get pushed by anything
	self->s.v.solid = SOLID_NOT;
	self->s.v.use = ( func_t ) func_portal_use;
	self->s.v.effects = EF_BLUE | EF_RED | EF_DIMLIGHT;
	setmodel( self, self->s.v.model );
	G_bprint( 2, "portal spawned\n");
	G_bprint( 2, "mins %f %f %f\n", self->s.v.mins[0], self->s.v.mins[1],self->s.v.mins[2]);
	G_bprint( 2, "maxs %f %f %f\n", self->s.v.maxs[0], self->s.v.maxs[1],self->s.v.maxs[2]);

	G_bprint( 2, "pos1 %f %f %f\n", self->pos1[0], self->pos1[1],self->pos1[2]);
	G_bprint( 2, "pos2 %f %f %f\n", self->pos2[0], self->pos2[1],self->pos2[2]);
    vec3_t middle;
    VectorSet(middle, 0, 0, 0);
    VectorAdd(self->s.v.mins, self->s.v.maxs, middle);
    VectorScale(middle, 0.5f, middle);
	setorigin( self, PASSVEC3( self->s.v.origin ) );
//	setorigin( self, PASSVEC3(middle) );
	G_bprint( 2, "origin %f %f %f\n", self->s.v.origin[0], self->s.v.origin[1],self->s.v.origin[2]);

}
