#include "atpch.h"
#include "LayerStack.h"

namespace Atlas {
	Atlas::LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	Atlas::LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void Atlas::LayerStack::PushLayer(Layer * layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	void Atlas::LayerStack::PushOverlay(Layer * overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void Atlas::LayerStack::PopLayer(Layer * layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end()) {
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void Atlas::LayerStack::PopOverlay(Layer * overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end()) {
			m_Layers.erase(it);
		}
	}

}