#include <string>
#include <tuple>

#include "bag_of_visual_words.h"

using ImageRow = image_browser::ImageRow;
using ScoredImage = image_browser::ScoredImage;

std::string image_browser::AddFullRow(const ImageRow& row, bool first_row)
{
  std::string browser_row;
  browser_row += html_writer::OpenRow();
  for (int i = 0; i < row.size(); i++)
  {
    if (i == 0 && first_row)
    {
      browser_row += html_writer::AddImage(std::get<0>(row[i]), std::get<1>(row[i]), true);
    }
    else
    {
      browser_row += html_writer::AddImage(std::get<0>(row[i]), std::get<1>(row[i]));
    }
  }
  browser_row += html_writer::CloseRow();
  return browser_row;
}

void image_browser::CreateImageBrowser(const std::string& title, const std::string& stylesheet,
                                       const std::vector<ImageRow>& rows, const std::string& output_path)
{
  std::string img_browser_str;
  img_browser_str += html_writer::OpenDocument();
  img_browser_str += html_writer::AddTitle(title);
  img_browser_str += html_writer::AddCSSStyle(stylesheet);
  img_browser_str += html_writer::OpenBody();
  bool first_row = true;
  for (ImageRow row : rows)
  {
    img_browser_str += image_browser::AddFullRow(row, first_row);
    first_row = false;
  }
  img_browser_str += html_writer::CloseBody();
  img_browser_str += html_writer::CloseDocument();
  std::ofstream out_file(output_path);
  out_file << img_browser_str;
  out_file.close();
}