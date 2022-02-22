// #include <htmlwriter/html_writer.hpp>
#include <string>

#include "bag_of_visual_words.h"

namespace fs = boost::filesystem;

std::string html_writer::OpenDocument()
{
  return fmt::format("<!DOCTYPE html>\n<html>\n");
}

std::string html_writer::CloseDocument()
{
  return fmt::format("</html>\n");
}

std::string html_writer::AddCSSStyle(const std::string& stylesheet)
{
  return fmt::format(
      "<head>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"{}\" "
      "/>\n</head>\n",
      stylesheet);
}

std::string html_writer::AddTitle(const std::string& title)
{
  return fmt::format("<title>{}</title>\n", title);
}

std::string html_writer::OpenBody()
{
  return fmt::format("<body>\n");
}

std::string html_writer::CloseBody()
{
  return fmt::format("</body>\n");
}

std::string html_writer::OpenRow()
{
  return fmt::format("<div class=\"row\">\n");
}

std::string html_writer::CloseRow()
{
  return fmt::format("</div>\n");
}

std::string html_writer::AddImage(const std::string& img_path, float score, bool highlight)
{
  if (fs::path(img_path).extension() == ".png" || fs::path(img_path).extension() == ".jpg")
  {
    std::string style_string = highlight ? "border: 5px solid green;" : "";
    return fmt::format(
        "<div class=\"column\" style=\"{0}\">\n<h2>{1}</h2>\n<img "
        "src=\"{2}\" />\n<p>score = {3}</p>\n</div>\n",
        style_string, fs::path(img_path).filename().string(), img_path, fmt::format("{:.2f}", score));
  }
  else
  {
    return "";
  }
}

// int main(){
//     html_writer::OpenDocument();
//     html_writer::AddTitle("Ensayo");
//     html_writer::AddCSSStyle("style.css");
//     html_writer::OpenBody();
//     html_writer::OpenRow();
//     html_writer::AddImage("data/000000.png", 10.0f);
//     html_writer::AddImage("data/000100.png", 50.0f, true);
//     html_writer::CloseRow();
//     html_writer::CloseBody();
//     html_writer::CloseDocument();

//     return 0;
// }
