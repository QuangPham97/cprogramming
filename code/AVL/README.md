# Define Red - Back Binary Tree
- Một cây đỏ đen là một kiểu cây nhị phân tự cân bằng trong đó mỗi node có thêm đặc tính là màu (đỏ hoặc đen). Màu được sử dụng để đảm bảo cây được cân băng
trong quá trình thêm, xóa node. Mặc dù tính cân bằng của cây không hoàn hảo nhưng  nó cũng đủ để  tìm kiếm với độ phức tạp O(logn) (n là số  lượng phần tử của cây)

# Rule that every Red-Black Tree Follows:
- Mỗi một node có một trong hai màu đỏ hoặc đen
- Node root luôn luôn là node có màu đen
- Không tồn tại hai node màu đỏ liền kề nhau (Một node red không thể có node cha màu đỏ hoặc node con màu đỏ)
- Mỗi đường từ một node (bao gồm cả node gốc) đến bất kì node con (NULL) nào đều có cùng số lượng node đen
- Tất cả các node lá đều là node màu đen