#pragma once

#include <iostream>

#include "Resource.hpp"

class ResourceManager
{
    private:
    Resource* m_res;

    public:
    ResourceManager() : m_res{new Resource{}}
    {

    }

    ~ResourceManager()
    {
        delete m_res;
    }

    ResourceManager(const ResourceManager& res_menager) : m_res{new Resource{*res_menager.m_res}}
    {

    }

    ResourceManager& operator=(const ResourceManager& res_menager)
    {
        if(this != &res_menager)
        {
            delete m_res;

            m_res = new Resource{*res_menager.m_res};
        }

        return *this;
    }

    ResourceManager(ResourceManager&& res_menager) : m_res{res_menager.m_res}
    {
        res_menager.m_res = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& res_menager)
    {
        if(this != &res_menager)
        {
            delete m_res;

            m_res = res_menager.m_res;

            res_menager.m_res = nullptr;
        }

        return *this;
    }

    double get()
    {
        return m_res->get();
    }
};
