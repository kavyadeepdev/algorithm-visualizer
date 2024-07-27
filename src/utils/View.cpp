#include <string>
namespace View {
enum ViewOptions {
	MainMenu,
	SortingMenu,
	PathfindingMenu,
	SortingVisualizer,
	PathfindingVisualizer,
	InvalidView
};
ViewOptions ResolveView(const std::string &view) {
	if (view == "main-menu") {
		return MainMenu;
	} else if (view == "sorting-menu") {
		return SortingMenu;
	} else if (view == "pathfinding-menu") {
		return PathfindingMenu;
	} else if (view == "sorting-visualizer") {
		return SortingVisualizer;
	} else if (view == "pathfinding-visualizer") {
		return PathfindingVisualizer;
	} else {
		return InvalidView;
	}
}
} // namespace View
