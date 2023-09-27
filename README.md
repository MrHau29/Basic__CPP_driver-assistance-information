# Chương Trình hiển thông tin hỗ trợ lái xe 

Tác giả: Hoàng Văn Hậu

Timeline: 20/9/2022 - 23/9/2022


Email: hoanghau@290698@gmail.com

Chương trình được viết trên IDE: Microsoft Visual Studio Community 2022.


Kiến Thức sử dụng để hoàn thành dự án:

	-Thao tác cơ bản với hướng đối tượng
	-Ghi/sửa/xóa tệp nhị phân 
	-Con trỏ cơ bản và thao tác với con trỏ
	-Sử dụng  thuật toán để sắp xếp
 

Tổng quan chương trình: 	
	Xây dựng chương trình hỗ trợ thông báo cho lái xe , để cho việc lái xe trở nên an toàn hơn.

Các chức năng chính:
1. Tính năng đăng nhập, Chức năng này tương đương với việc mở khóa xe và nổ máy.
	Ở phần này cần phải nhập vào một mã số cá nhân để đăng nhập. 
	Sau đó sánh dãy số mã số cá nhân vừa nhập với file có chứa mã số cá nhân để mở khoá xe.
	Dữ liệu sẽ được đọc từ file và cập nhật vào file sau mỗi lần cài đặt và đăng nhâp
2. Chức năng cảnh báo:
 	 + Tương tự phần đăng nhập, dữ liệu sẽ được kiểm tra trong file, và sẽ được cập nhật vào file 
	khi người dùng lựa chọn cài đặt lại
  	+ Cảnh báo khoảng cách an toàn ở một số dải vận tốc:
		Với 03 mức cảnh báo tốc độ <Mức1> - <Mức2> - <Mức3> (km/h)
			Nhỏ hơn <Mức1> : Cảnh báo chú ý phải giữ khoảng cách tối thiểu là 20m
			<Mức1> ~ <Mức2> : Cảnh báo chú ý phải giữ khoảng cách tối thiểu là 55m
			<Mức2> ~ <Mức3> : Cảnh báo chú ý phải giữ khoảng cách tối thiểu là 70m
			Lớn hơn <Mức3> : Cảnh báo chú ý phải giữ khoảng cách tối thiểu là 100m
  	+ Cảnh báo tốc độ cao (tốc độ lớn hơn 60km/h với D hoặc 20km/h với R)
  	+ Cảnh báo chuyển đổi cần số
	Cảnh báo không thể về số N/P khi xe chưa dừng hẳn.
	Cảnh báo không thể chuyển đổi trực tiếp R<->D khi xe vẫn còn di chuyển
3. Đưa ra lựa chọn sử dụng cần số để thay đổi số (R:Lùi/N:Tạm dừng/D:Tiến/P:Đỗ xe) 
   và điều khiển tốc độ (tăng/giảm tốc độ, phanh)
	+ Số P: Tức là đưa xe về chế độ đỗ xe. Ở chế độ này hộp số sẽ ở chế độ P và bánh xe sẽ bị bó cứng
	+ Số N: Cũng là đưa xe về chế độ đỗ xe. Chỉ khác số P là bánh xe không bị bó cứng, nếu không sử dụng phanh thì ô tô sẽ bị trôi
	+ Số R: Đơn giản là để số lùi
	+ Số D: Đơn giản là số tiến
4. Tắt máy (khi lựa chọn tắt máy) và đưa ra thông báo chào tạm biệt
