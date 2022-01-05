//---------------------------------------------------------------------------

#pragma hdrstop

#include "TextureStorage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TTextureStorage::TTextureStorage() {
    this->textures.clear(); //sanity check
}

TTextureStorage::~TTextureStorage() {
	auto it = this->textures.begin();
	while(it != this->textures.end()) {
		delete it->second;
	}
}

void TTextureStorage::DefineTexture(const String name, const String path) {
	if(this->textures.find(name) != this->textures.end()) {
		throw "Tried to define texture with the same name without undefining!";
	}
	TTexture* texture = new TTexture(path);
	this->textures.insert({name, texture});
}

void TTextureStorage::UndefineTexture(const String name) {
	if(this->textures.find(name) != this->textures.end()) {
		delete this->textures.at(name);
        this->textures.erase(name);
    }
}

void TTextureStorage::LoadTexture(const String name) {
	this->textures.at(name)->Load();
}

void TTextureStorage::UnloadTexture(const String name) {
	this->textures.at(name)->Unload();
}

void TTextureStorage::LoadAllTextures() {
	auto it = this->textures.begin();
	while(it != this->textures.end()) {
		it->second->Load();
	}
}

void TTextureStorage::UnloadAllTextures() {
	auto it = this->textures.begin();
	while(it != this->textures.end()) {
		it->second->Unload();
	}
}

TTexture* TTextureStorage::GetTexture(const String name) {
    return this->textures.at(name);
}
