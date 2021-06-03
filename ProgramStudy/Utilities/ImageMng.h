#pragma once
#include <string>
#include <unordered_map>

class ImageMng
{
public:
	static ImageMng& Instance();

	bool AddImage(const std::string& key, const std::string& fileName);
	int GetID(const std::string& key);
	
private:
	ImageMng();
	~ImageMng();
	
private:
	// Don't allow copy and move semantics
	ImageMng(const ImageMng&);
	ImageMng(ImageMng&&) noexcept;
	void operator = (const ImageMng&);
	void operator = (ImageMng&&) noexcept;
	//

private:
	std::unordered_map<std::string, int> m_imageIDs;
};

