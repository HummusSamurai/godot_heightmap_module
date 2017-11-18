#ifndef HEIGHT_MAP_CHUNK_H
#define HEIGHT_MAP_CHUNK_H

#include <math/math_2d.h>
#include <scene/3d/mesh_instance.h>

// Container for chunk objects
class HeightMapChunk {
public:
	Point2i cell_origin;

	HeightMapChunk(Spatial *p_parent, Point2i p_cell_pos, Ref<Material> p_material);
	~HeightMapChunk();

	void set_mesh(Ref<Mesh> mesh);
	void clear();
	void set_material(Ref<Material> material);
	void enter_world(World &world);
	void exit_world();
	void parent_transform_changed(const Transform &parent_transform);

	void set_visible(bool visible);
	bool is_visible() const { return _visible; }

	void set_active(bool p_active) { _active = p_active; }
	bool is_active() const { return _active; }

	bool is_pending_update() const { return _pending_update; }
	void set_pending_update(bool pending_update) { _pending_update = pending_update; }

	void set_aabb(AABB aabb);

private:
	bool _visible;
	bool _active;
	bool _pending_update;

	RID _mesh_instance;
	// Need to keep a reference so that the mesh RID doesn't get freed
	// TODO Use RID directly, no need to keep all those meshes in memory
	Ref<Mesh> _mesh;
};

#endif // HEIGHT_MAP_CHUNK_H
