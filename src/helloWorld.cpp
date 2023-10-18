#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
  #include <windows.h> //windows only header required
#endif

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <implot.h>

#include <fmt/format.h>
#include "../lib/ImGuiFileDialog/ImGuiFileDialog.h"

static void glfw_error_callback(int error, const char *description) {
  fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

// Prototype funct for testing file picker compilation
std::vector<std::string>* drawGUI(std::vector<std::string>* fileP);

int main(int, char **) {
  // Setup window
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit())
    return 1;

  const char *glsl_version = "#version 130";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  // Create window
  GLFWwindow *window = glfwCreateWindow(
      1280, 720, "Dear ImGUI GLFW+OpenGL3 example", NULL, NULL);
  if (window == NULL)
    return 1;
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // VSync Enable

  // Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImPlot::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;

  // Dear ImGui style
  ImGui::StyleColorsDark();

  // Setup Platform/Render backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);

  // Window booleans
  bool show_demo_window = true;
  bool show_another_window = false;
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  // Test file picker
  bool filePick = false;
  std::vector<std::string>* fileInfo = nullptr;

  ImGuiWindowFlags flags = ImGuiWindowFlags_AlwaysAutoResize;

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // start Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // windows here
    {
      ImGui::Begin("Enhanced Genetic Path Planning Algorithm", NULL, flags);
      ImGui::Text(
          "Select a properly formatted txt or csv file using the button below");
      // checkbox to display a loaded map
      filePick = ImGui::Checkbox("Display Loaded Map", &show_another_window);
      fileInfo = drawGUI(fileInfo);
      ImGui::End();
    }

    // rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w,
                 clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
  } // End While
    // cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  ImPlot::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}


std::vector<std::string>* drawGUI(std::vector<std::string>* fileP) {
  // open Dialog Simple std::cout << fmt::format("DrawGUI");
  if (ImGui::Button("Open File Dialog")) {
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".csv,.txt", ".");
  }
  static std::vector<std::string> fileInfo;
  static std::string filePathName;
  static std::string filePath;
  static std::string fileName;
  // display
  if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) {
    // action if OK
    if (ImGuiFileDialog::Instance()->IsOk()) {
      filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
      filePath     = ImGuiFileDialog::Instance()->GetCurrentPath();
      fileName     = filePathName.substr(filePath.length() + 1);

      fileInfo.push_back(filePathName);
      fileInfo.push_back(filePath);
      fileInfo.push_back(fileName);

      // const char *fileP = filePathName.c_str();
      //  action
      //  ImGui::Text("%s", fileP);
#ifndef NDEBUG
      std::cout << fmt::format("{}", fileInfo[2]) << std::endl;
#endif
      ImGuiFileDialog::Instance()->Close();
      if (ImGui::GetIO().KeyAlt) printf(""); // Set a debugger breakpoint here!
      return &fileInfo;
    }

    // close
    ImGuiFileDialog::Instance()->Close();
    return nullptr;
  }
  if (fileP != nullptr) return fileP;
  return nullptr;
}