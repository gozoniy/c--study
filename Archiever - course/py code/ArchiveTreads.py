import os
import zipfile
from PyQt5.QtCore import QThread, pyqtSignal

class CompressionThread(QThread):
    # Сигналы для обновления прогресса и завершения операции
    updateProgress = pyqtSignal(int)
    compressionFinished = pyqtSignal()

    def __init__(self, file_paths, save_path, parent=None):
        super().__init__(parent)
        self.file_paths = file_paths
        self.save_path = save_path

    def run(self):
        # Создаем архив
        with zipfile.ZipFile(self.save_path, 'w') as zipf:
            for i, path in enumerate(self.file_paths):
                if os.path.isfile(path):
                    zipf.write(path, os.path.basename(path))  # Добавляем файл в архив
                elif os.path.isdir(path):
                    for root, dirs, files in os.walk(path):
                        for file in files:
                            file_path = os.path.join(root, file)
                            zipf.write(file_path, os.path.relpath(file_path, path))  # Добавляем файлы из директории в архив
                # Отправляем сигнал для обновления прогресса
                self.updateProgress.emit((i + 1) * 100 // len(self.file_paths))
        # Отправляем сигнал о завершении операции
        self.compressionFinished.emit()

class UnzipThread(QThread):
    progressChanged = pyqtSignal(int)

    def __init__(self, archive_path, extract_to):
        super().__init__()
        self.archive_path = archive_path
        self.extract_to = extract_to

    def run(self):
        with zipfile.ZipFile(self.archive_path, 'r') as zip_ref:
            file_count = len(zip_ref.infolist())
            extracted_files = 0
            for file_info in zip_ref.infolist():
                zip_ref.extract(file_info, self.extract_to)
                extracted_files += 1
                progress = int(extracted_files / file_count * 100)
                self.progressChanged.emit(progress)
