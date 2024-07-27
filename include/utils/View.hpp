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
ViewOptions ResolveView(const std::string &scene);
} // namespace View
